#include "G4RunManager.hh"
#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4MTRunManager.hh"
#include "AnalysisManager.hh"
#include "ActionInitialization.hh"
#include "G4UIExecutive.hh"
#include "G4GDMLParser.hh"

int main(int argc, char** argv)
{
  G4cout << G4endl;
  G4cout << "Usage: dose <intput_gdml_file:mandatory>"
         << G4endl;
  G4cout << G4endl;

  if (argc<2)
  {
     G4cout << "Error! Mandatory input file is not specified!" << G4endl;
     G4cout << G4endl;
     return -1;
  }

  G4GDMLParser parser;
  parser.Read(argv[1]);

#ifdef G4MULTITHREADED
  G4MTRunManager* pRunManager = new G4MTRunManager;
  pRunManager->SetNumberOfThreads(4); 
#else  
  G4RunManager* pRunManager = new G4RunManager;
#endif

  AnalysisManager* analysis = new AnalysisManager();
 
  DetectorConstruction* detector = new DetectorConstruction(parser, analysis);  
    
  pRunManager -> SetUserInitialization(detector);

  G4VUserPhysicsList* physics = new PhysicsList();
  
  pRunManager -> SetUserInitialization(physics); 

   // User action initialization  

  ActionInitialization* actions = new ActionInitialization(analysis);
  pRunManager->SetUserInitialization(actions);

  G4VisManager* visManager = new G4VisExecutive();
  visManager->Initialize();
 
  // Get the pointer to the User Interface manager
  //
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  if(argc == 2){

    /*this sets up the user interface to run in interactive mode */
    G4UIExecutive* ui = new G4UIExecutive(argc, argv); 
    G4cout << " UI session starts ..." << G4endl;
    UImanager -> ApplyCommand("/control/execute vis.mac");
    //now, we run in interactive mode so tell the UI manager to read the vis.mac macro file and 
    //UI->ApplyCommand("/control/execute vis.mac"); 
    ui -> SessionStart();
    delete ui;

  } else { 
    //otherwise we run in batch mode
    G4String command = "/control/execute ";//create first part of command
    G4String fileName = argv[2];//second part is the file name that was typed at the command line 
    UImanager->ApplyCommand(command+fileName);//join the two and pass to the UI manager for interpretation
  }

  delete visManager;
  delete analysis; 
  delete pRunManager;
  
  return 0;
}
