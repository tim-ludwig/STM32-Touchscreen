/*
 * BoundingBox.h
 *
 *  Created on: 16 Dec 2021
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_BOUNDINGBOX_H_
#define TOUCHLIB_BOUNDINGBOX_H_

#include "lib.h"

namespace touchlib {
	class BoundingBox {
	private:
		WORD left, top, right, bottom;

	public:
		BoundingBox(WORD x, WORD y, WORD w, WORD h);

		bool contains(WORD x, WORD y) const;
		void resizeToFit(WORD x, WORD y);
		void resizeToFit(BoundingBox const&);

		WORD x();
		WORD y();
		WORD width();
		WORD height();
	};
}

#endif /* TOUCHLIB_BOUNDINGBOX_H_ */
