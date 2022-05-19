#ifndef TEXTURESMANAGER_H_INCLUDED
#define TEXTURESMANAGER_H_INCLUDED

#include "include.h"
#include "GameEngine.h"
class ManageTexture
{
    public:

        //Init
        ManageTexture();

        //Close
        ~ManageTexture();

        //Load image
        bool loadImage(string path);

        #if defined (SDL_TTF_MAJOR_VERSION)
        //Creates image from font string
        bool loadFromRenderedText (string textureText, SDL_Color textColor);
        #endif

        //Destroy
        void free();

        //Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );

		//Renders texture at given point
		void render(int x, int y, SDL_Rect* clip , double angle , SDL_Point* center , SDL_RendererFlip &flip);

		//void render(SDL_Rect src,SDL_Rect dst, double angle, SDL_RendererFlip &flip);

		//void setPos( int x, int y, int w, int h, SDL_Rect &rect);

		//Gets image dimensions
		int getWidth();
		int getHeight();

        int getPosX();
        int getPosY();

    private:
		//The actual hardware texture
		SDL_Texture* mTexture;

        //Image dimensions
		int mWidth;
		int mHeight;

		int mPosX,mPosY;
};

#endif // TEXTURESMANAGER_H_INCLUDED
