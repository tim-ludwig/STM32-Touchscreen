/*
 * ColorTheme.h
 *
 *  Created on: 16 Jan 2022
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_COLORTHEME_H_
#define TOUCHLIB_COLORTHEME_H_

#include "lib.h"

namespace touchlib {
	class ColorTheme {
	public:
		const WORD primary, lightPrimary;
		ColorTheme(WORD primary, WORD lightPrimary);
	};
}

#endif /* TOUCHLIB_COLORTHEME_H_ */
