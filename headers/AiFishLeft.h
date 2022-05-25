#ifndef AIFISHLEFT_H_INCLUDED
#define AIFISHLEFT_H_INCLUDED

#include "include.h"
#include "TexturesManager.h"
#include "GameEngine.h"
#include "Timer.h"
class AiFishLeft_Level1
{
      public:

        const int AI_WIDTHL1 = 32;

        const int AI_HEIGHTL1 = 27;

		AiFishLeft_Level1();

		~AiFishLeft_Level1();

		void update();

		void moveAIL1(int incaseAI);

		void renderAIL1( int i);

		void generateAILL1(int i);

        double getPosXL1(int i);

        double getPosYL1(int i);

        double getWidthL1(int i);

        double getHeightL1(int i);

        double AiPosX[maxAIfishes_level1], AiPosY[maxAIfishes_level1];

        double AiVelX[maxAIfishes_level1], AiVelY[maxAIfishes_level1];

    private:

        double frame[maxAIfishes_level1];

        Timer timer[maxAIfishes_level1];

        SDL_RendererFlip flip=SDL_FLIP_HORIZONTAL;

        ManageTexture gAiFishLeft_Level1[maxAIfishes_level1*3];
};

class AiFishLeft_Level2
{
   public:
        // W and H of AIs
        const int AI_WIDTHL2 = 115;

		const int AI_HEIGHTL2 = 54;

		AiFishLeft_Level2();

		~AiFishLeft_Level2();

		void update();

		void moveAIL2(int incaseAI);

		void renderAIL2( int i);

		void generateAILL2(int i);

        double getPosXL2(int i);

        double getPosYL2(int i);

        double getWidthL2(int i);

        double getHeightL2(int i);

        double AiPosX[maxAIfishes_level2], AiPosY[maxAIfishes_level2];

        double AiVelX[maxAIfishes_level2], AiVelY[maxAIfishes_level2];

    private:

        double frame[maxAIfishes_level2];

        Timer timer[maxAIfishes_level2];

        ManageTexture gAiFishLeft_Level2[maxAIfishes_level2*4];

        SDL_RendererFlip flip=SDL_FLIP_HORIZONTAL;
};


class AiFishLeft_Level3
{
     public:
        // W and H of AIs
        const int AI_WIDTHL3 = 200;
		const int AI_HEIGHTL3 = 124;

		AiFishLeft_Level3();

		~AiFishLeft_Level3();

        void update();

		void moveAIL3(int incaseAI);

		void renderAIL3( int i);

		void generateAILL3(int i);

        double getPosXL3(int i);

        double getPosYL3(int i);

        double getWidthL3(int i);

        double getHeightL3(int i);

        double AiPosX[maxAIfishes_level3], AiPosY[maxAIfishes_level3];

        double AiVelX[maxAIfishes_level3], AiVelY[maxAIfishes_level3];

    private:

        double frame[maxAIfishes_level3];

        Timer timer[maxAIfishes_level3];

        ManageTexture gAiFishLeft_Level3[maxAIfishes_level3*3];

        SDL_RendererFlip flip=SDL_FLIP_NONE;
};


#endif // AIFISHLEFT_H_INCLUDED
