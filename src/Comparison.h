#ifndef COMPARISON_H
#define COMPARISON_H

#include "ColorSpace.h"

namespace ColorSpace {
	struct EuclideanComparison {
		static double Compare(IColorSpace *a, IColorSpace *b);
	};

	struct Cie1976Comparison {
		static double Compare(IColorSpace *a, IColorSpace *b);
	};


	struct Cie94Comparison {
		enum APPLICATION {
			GRAPHIC_ARTS = 0,
			TEXTILES
		};

		struct Application {
			Application() {
				kl = 0.0;
				k1 = 0.0;
				k2 = 0.0;
			}
			double kl;
			double k1;
			double k2;
			Application(APPLICATION appType);
		};

		static double Compare(IColorSpace *a, IColorSpace *b, APPLICATION appType=GRAPHIC_ARTS);
	};


	struct Cie2000Comparison {
		static double Compare(IColorSpace *a, IColorSpace *b);
	};


	struct CmcComparison {
		static const double defaultLightness;
		static const double defaultChroma;
		static double Compare(IColorSpace *a, IColorSpace *b);
	};
}

#endif // COMPARISON_H

