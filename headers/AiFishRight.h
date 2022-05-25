#ifndef AIFISHRIGHT_H_INCLUDED
#define AIFISHRIGHT_H_INCLUDED

#include "include.h"
#include "TexturesManager.h"
#include "GameEngine.h"
#include "Timer.h"
class AiFishRight_Level1
{
    public:

		const int AI_WIDTHR1 = 32 ;
		const int AI_HEIGHTR1 = 27;

		AiFishRight_Level1();

        ~AiFishRight_Level1();

        void update();

		void moveAIL1(int incaseAI);

		void renderAIL1( int i);

        void generateAIRL1(int i);

        double getPosXR1(int i);

        double getPosYR1(int i);

        double getWidthR1(int i);

        double getHeightR1(int i);

        double AiPosX[maxAIfishes_level1], AiPosY[maxAIfishes_level1];

        double AiVelX[maxAIfishes_level1], AiVelY[maxAIfishes_level1];

    private:

        double frame[maxAIfishes_level1];

        Timer timer[maxAIfishes_level1];

        SDL_RendererFlip flip=SDL_FLIP_NONE;

        ManageTexture gAiFishRight_level1[maxAIfishes_level1*3];
};

class AiFishRight_Level2
{
    public:

		const int AI_WIDTHR2 = 115 ;
		const int AI_HEIGHTR2 = 54;

		AiFishRight_Level2();

        ~AiFishRight_Level2();

        void update();

		void moveAIL2(int incaseAI);

		void renderAIL2( int i);

        void generateAIRL2(int i);

        double getPosXR2(int i);

        double getPosYR2(int i);

        double getWidthR2(int i);

        double getHeightR2(int i);

        double AiPosX[maxAIfishes_level2], AiPosY[maxAIfishes_level2];

        double AiVelX[maxAIfishes_level2], AiVelY[maxAIfishes_level2];

    private:

        double frame[maxAIfishes_level2];

        Timer timer[maxAIfishes_level2];

        SDL_RendererFlip flip=SDL_FLIP_NONE;

        ManageTexture gAiFishRight_level2[maxAIfishes_level2*4];
};

class AiFishRight_Level3
{
    public:

		const int AI_WIDTHR3 = 200 ;
		const int AI_HEIGHTR3 = 124;

		AiFishRight_Level3();

        ~AiFishRight_Level3();

        void update();

		void moveAIL3(int incaseAI);

		void renderAIL3( int i);

        void generateAIRL3(int i);

        double getPosXR3(int i);

        double getPosYR3(int i);

        double getWidthR3(int i);

        double getHeightR3(int i);

        double AiPosX[maxAIfishes_level3], AiPosY[maxAIfishes_level3];

        double AiVelX[maxAIfishes_level3], AiVelY[maxAIfishes_level3];

    private:

        int frame[maxAIfishes_level3];

        Timer timer[maxAIfishes_level3];

        SDL_RendererFlip flip=SDL_FLIP_HORIZONTAL;

        ManageTexture gAiFishRight_level3[maxAIfishes_level3*3];
};

#endif // AIFISHRIGHT_H_INCLUDED
