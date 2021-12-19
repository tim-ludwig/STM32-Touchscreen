/*
 * BoundingBox.h
 *
 *  Created on: 16 Dec 2021
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_BOUNDINGBOX_H_
#define TOUCHLIB_BOUNDINGBOX_H_

namespace touchlib {
	class BoundingBox {
	public:
		int x;
		int y;
		int width;
		int height;

		BoundingBox(int x, int y, int width, int height);

		bool contains(int x, int y);
	};
}

#endif /* TOUCHLIB_BOUNDINGBOX_H_ */
