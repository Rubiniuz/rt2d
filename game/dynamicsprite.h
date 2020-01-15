#ifndef DYNAMICSPRITE_H
#define DYNAMICSPRITE_H

#include <rt2d/entity.h>

/// @brief A pixel
struct Pixel {
	/// @brief position relative to the 'pivotpoint' of a pixelsprite or canvas (0.0)
	Point2i position;
	/// @brief color of the pixel
	RGBAColor color;
  /// @brief health of the pixel
  int health;

	/// @brief constructor
	/// @param pos the position of the pixel
	/// @param c the color of the pixel
	Pixel(Point2i pos, RGBAColor c) { position = pos; color = c; };
};
/// @brief The Canvas class is an Entity with a dynamic Texture. It fills the window.
class DynamicSprite: public Entity
{
	public:
		/// @brief constructor
		DynamicSprite();
		/// @brief overloaded constructor
		DynamicSprite(std::string tgafile, int width, int height, int tilewidth, int tileheight, int pixelsize);
		/// @brief destructor
		virtual ~DynamicSprite();

		/// @brief empty update function
		virtual void update(float deltaTime);

		/// @brief color a single pixel
		/// @param x position of pixel
		/// @param y position of pixel
		/// @param color of pixel
		/// @return void
		void setPixel(int x, int y, RGBAColor color);
		/// @brief get a single pixel color from canvas
		/// @param x position of pixel
		/// @param y position of pixel
		/// @return color of pixel on canvas
		RGBAColor getPixel(int x, int y);
		/// @brief clears a single pixel color to canvas background color
		/// @param x position of pixel
		/// @param y position of pixel
		/// @return void
		void clearPixel(int x, int y);
		/// @brief fill the canvas with a single color
		/// @param color to fill with
		/// @return void
		void fill(RGBAColor color);

		/// @brief get the width of the canvas
		/// @return _width of canvas
		int width() { return _width; };
		/// @brief get the height of the canvas
		/// @return _height of canvas
		int height() { return _height; };

		Point2 worldposition() { return _worldposition; };
		void worldposition(Point2 pos) { _worldposition = pos; };

		Point3 worldrotation() { return _worldrotation; };
		void worldrotation(Point3 rot) { _worldrotation = rot; };

		/// @brief the backgroundcolor of the canvas
		RGBAColor backgroundcolor;

		void FromTGA(std::string tgafile, int width, int height, int tilewidth, int tileheight, int pixelsize);

	private:
		/// @brief _framebuffer the internal pixelbuffer
		PixelBuffer* _framebuffer;
		Sprite* dynamic_sprite;
		Entity* sprite_container;

		Point2 _worldposition;
		Point3 _worldrotation;

		/// @brief width of the canvas
		int _width;
		/// @brief height of the canvas
		int _height;
};

#endif /* DYNAMICSPRITE_H */
