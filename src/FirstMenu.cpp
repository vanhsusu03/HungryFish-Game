#include "FirstMenu.h"

void loadSource()
{
   gPlayGame.loadImage(playgame);
   gInstruction.loadImage(instruc);
   gOptions.loadImage(option);
   gQuit.loadImage(quit);
   gHighScores.loadImage(highsc);
   gLogo.loadImage(logo);
   gCredits.loadImage(cred);
   gResume.loadImage(resume);
   gNewGame.loadImage(newgame);

}

void inputFirstMenu()
{

}

void firstmenu()
{
    gLogo.render(500,300,nullptr,0,nullptr,flip);
}
