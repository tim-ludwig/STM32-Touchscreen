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
		int left, right, top, bottom;

		BoundingBox(int x, int y, int w, int h);

		bool contains(int x, int y) const;
		void resizeToFit(int x, int y);
		void resizeToFit(BoundingBox const&);

		int x();
		int y();
		int width();
		int height();
	};
}

#endif /* TOUCHLIB_BOUNDINGBOX_H_ */
