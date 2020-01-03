#include "testconfig.h"
#define TEST_FUNC_F_F __MATH_PRECNAME(acosh)
#include "testdriver.h"



static test_f_f_data const facosh_data[] = {
	{ __LINE__, ZERO_P, QNAN_P, 0 },
	{ __LINE__, ZERO_M, QNAN_P, 0 },
	{ __LINE__, INF_P, INF_P, FLAG_FAIL_ARANYM }, /* glibc returns NaN */
	{ __LINE__, INF_M, QNAN_P, 0 },
	{ __LINE__, QNAN_P, QNAN_P, 0 },
	{ __LINE__, QNAN_M, QNAN_P, 0 },
	{ __LINE__, SNAN_P, QNAN_P, 0 },
	{ __LINE__, SNAN_M, QNAN_P, 0 },

	/* x < 1:  */
	{ __LINE__, HEXCONSTE(0.75L, 0x3ffe, 0xc0000000L, 0x00000000L), QNAN_P, 0 },
	{ __LINE__, MIN_P, QNAN_P, 0 },
	{ __LINE__, SUBNORM_P, QNAN_P, FLAG_SUBNORM },
	{ __LINE__, SUBNORM_M, QNAN_P, FLAG_SUBNORM },
	{ __LINE__, MIN_M, QNAN_P, 0 },
	{ __LINE__, HEXCONSTE(-1.125L, 0xbfff, 0x90000000L, 0x00000000L), QNAN_P, 0 },
	{ __LINE__, MAX_M, QNAN_P, 0 },

	{ __LINE__, HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.00000011920928955078e+00, 0x3fff, 0x80000100L, 0x00000000L), HEXCONSTE(4.88281245149361720661e-04, 0x3ff3, 0xffffffd5L, 0x55556889L), 0 },
	{ __LINE__, HEXCONSTE(1.00000011920928955078e+00, 0x3fff, 0x80000100L, 0x00000000L), HEXCONSTE(4.88281245149361720661e-04, 0x3ff3, 0xffffffd5L, 0x55556889L), 0 },
	{ __LINE__, HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.00000000000000022204e+00, 0x3fff, 0x80000000L, 0x00000800L), HEXCONSTE(2.10734242554470155036e-08, 0x3fe5, 0xb504f333L, 0xf9de6393L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.00000011920928955078e+00, 0x3fff, 0x80000100L, 0x00000000L), HEXCONSTE(4.88281245149361720661e-04, 0x3ff3, 0xffffffd5L, 0x55556889L), 0 },
	{ __LINE__, HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.00000000000000022204e+00, 0x3fff, 0x80000000L, 0x00000800L), HEXCONSTE(2.10734242554470155036e-08, 0x3fe5, 0xb504f333L, 0xf9de6393L), FLAG_INEXACT },
#if defined(TEST_LDOUBLE) && LDBL_MANT_DIG >= 64
	{ __LINE__, HEXCONSTE(1.00000000000000000011e+00, 0x3fff, 0x80000000L, 0x00000001L), HEXCONSTE(4.65661287307739257812e-10, 0x3fe0, 0x80000000L, 0x00000000L), FLAG_INEXACT },
#endif
	{ __LINE__, HEXCONSTE(1.00000011920928955078e+00, 0x3fff, 0x80000100L, 0x00000000L), HEXCONSTE(4.88281245149361720661e-04, 0x3ff3, 0xffffffd5L, 0x55556889L), 0 },
	{ __LINE__, HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.00000000000000022204e+00, 0x3fff, 0x80000000L, 0x00000800L), HEXCONSTE(2.10734242554470155036e-08, 0x3fe5, 0xb504f333L, 0xf9de6393L), FLAG_INEXACT },
#if defined(TEST_LDOUBLE) && LDBL_MANT_DIG >= 64
	{ __LINE__, HEXCONSTE(1.00000000000000000011e+00, 0x3fff, 0x80000000L, 0x00000001L), HEXCONSTE(4.65661287307739257812e-10, 0x3fe0, 0x80000000L, 0x00000000L), FLAG_INEXACT },
#endif
	{ __LINE__, HEXCONSTE(1.00000011920928955078e+00, 0x3fff, 0x80000100L, 0x00000000L), HEXCONSTE(4.88281245149361720661e-04, 0x3ff3, 0xffffffd5L, 0x55556889L), 0 },
	{ __LINE__, HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.00000000000000022204e+00, 0x3fff, 0x80000000L, 0x00000800L), HEXCONSTE(2.10734242554470155036e-08, 0x3fe5, 0xb504f333L, 0xf9de6393L), FLAG_INEXACT },
#if defined(TEST_LDOUBLE) && LDBL_MANT_DIG >= 64
	{ __LINE__, HEXCONSTE(1.00000000000000000011e+00, 0x3fff, 0x80000000L, 0x00000001L), HEXCONSTE(4.65661287307739257812e-10, 0x3fe0, 0x80000000L, 0x00000000L), FLAG_INEXACT },
#endif
	{ __LINE__, HEXCONSTE(1.62500000000000000000e+00, 0x3fff, 0xd0000000L, 0x00000000L), HEXCONSTE(1.06673243190143557358e+00, 0x3fff, 0x888ab036L, 0x4cb301feL), 0 },
	{ __LINE__, HEXCONSTE(7.00000000000000000000e+00, 0x4001, 0xe0000000L, 0x00000000L), HEXCONSTE(2.63391579384963341721e+00, 0x4000, 0xa892138cL, 0xc021a4dfL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.00000000000000000000e+02, 0x4005, 0xc8000000L, 0x00000000L), HEXCONSTE(5.29829236561048459069e+00, 0x4001, 0xa98b9c6eL, 0x5e313451L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.00000000000000000000e+05, 0x400f, 0xc3500000L, 0x00000000L), HEXCONSTE(1.22060726455051737297e+01, 0x4002, 0xc34c12d4L, 0x90b800baL), 0 },
	{ __LINE__, HEXCONSTE(2.56000000000000000000e+02, 0x4007, 0x80000000L, 0x00000000L), HEXCONSTE(6.23832081032041410205e+00, 0x4001, 0xc7a052f6L, 0xc9096737L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(5.12000000000000000000e+02, 0x4008, 0x80000000L, 0x00000000L), HEXCONSTE(6.93147085192377244295e+00, 0x4001, 0xddce9bf5L, 0xc6135810L), 0 },
	{ __LINE__, HEXCONSTE(1.02400000000000000000e+03, 0x4009, 0x80000000L, 0x00000000L), HEXCONSTE(7.62461874774073403681e+00, 0x4001, 0xf3fce074L, 0xc07a474cL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(2.04800000000000000000e+03, 0x400a, 0x80000000L, 0x00000000L), HEXCONSTE(8.31776610711469360868e+00, 0x4002, 0x851591e9L, 0xdd5b8341L), 0 },
	{ __LINE__, HEXCONSTE(4.09600000000000000000e+03, 0x400b, 0x80000000L, 0x00000000L), HEXCONSTE(9.01091333237812749588e+00, 0x4002, 0x902cb375L, 0x5a78915cL), 0 },
	{ __LINE__, HEXCONSTE(8.19200000000000000000e+03, 0x400c, 0x80000000L, 0x00000000L), HEXCONSTE(9.70406052411394401229e+00, 0x4002, 0x9b43d4f7L, 0xd7958a5eL), 0 },
	{ __LINE__, HEXCONSTE(1.67772160000000000000e+07, 0x4017, 0x80000000L, 0x00000000L), HEXCONSTE(1.73286795139986318469e+01, 0x4003, 0x8aa122b9L, 0x9bea150eL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(3.35544320000000000000e+07, 0x4018, 0x80000000L, 0x00000000L), HEXCONSTE(1.80218266945585778235e+01, 0x4003, 0x902cb379L, 0x5a78925cL), 0 },
	{ __LINE__, HEXCONSTE(6.71088640000000000000e+07, 0x4019, 0x80000000L, 0x00000000L), HEXCONSTE(1.87149738751185232988e+01, 0x4003, 0x95b84439L, 0x19070e89L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.34217728000000000000e+08, 0x401a, 0x80000000L, 0x00000000L), HEXCONSTE(1.94081210556784686493e+01, 0x4003, 0x9b43d4f8L, 0xd7958a6eL), 0 },
	{ __LINE__, HEXCONSTE(2.68435456000000000000e+08, 0x401b, 0x80000000L, 0x00000000L), HEXCONSTE(2.01012682362384139702e+01, 0x4003, 0xa0cf65b8L, 0x96240642L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(5.36870912000000000000e+08, 0x401c, 0x80000000L, 0x00000000L), HEXCONSTE(2.07944154167983592824e+01, 0x4003, 0xa65af678L, 0x54b28211L), 0 },
	{ __LINE__, HEXCONSTE(1.07374182400000000000e+09, 0x401d, 0x80000000L, 0x00000000L), HEXCONSTE(2.14875625973583045912e+01, 0x4003, 0xabe68738L, 0x1340fddeL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(2.14748364800000000000e+09, 0x401e, 0x80000000L, 0x00000000L), HEXCONSTE(2.21807097779182499017e+01, 0x4003, 0xb17217f7L, 0xd1cf79acL), 0 },
	{ __LINE__, HEXCONSTE(4.29496729600000000000e+09, 0x401f, 0x80000000L, 0x00000000L), HEXCONSTE(2.28738569584781952105e+01, 0x4003, 0xb6fda8b7L, 0x905df579L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(8.58993459200000000000e+09, 0x4020, 0x80000000L, 0x00000000L), HEXCONSTE(2.35670041390381405210e+01, 0x4003, 0xbc893977L, 0x4eec7147L), 0 },
	{ __LINE__, HEXCONSTE(2.81474976710656000000e+14, 0x402f, 0x80000000L, 0x00000000L), HEXCONSTE(3.39642118474373201631e+01, 0x4004, 0x87db5a59L, 0xbca2d928L), 0 },
	{ __LINE__, HEXCONSTE(5.62949953421312000000e+14, 0x4030, 0x80000000L, 0x00000000L), HEXCONSTE(3.46573590279972654701e+01, 0x4004, 0x8aa122b9L, 0x9bea170eL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.12589990684262400000e+15, 0x4031, 0x80000000L, 0x00000000L), HEXCONSTE(3.53505062085572107806e+01, 0x4004, 0x8d66eb19L, 0x7b3154f5L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(2.25179981368524800000e+15, 0x4032, 0x80000000L, 0x00000000L), HEXCONSTE(3.60436533891171560912e+01, 0x4004, 0x902cb379L, 0x5a7892dcL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(4.50359962737049600000e+15, 0x4033, 0x80000000L, 0x00000000L), HEXCONSTE(3.67368005696771013982e+01, 0x4004, 0x92f27bd9L, 0x39bfd0c2L), 0 },
	{ __LINE__, HEXCONSTE(9.00719925474099200000e+15, 0x4034, 0x80000000L, 0x00000000L), HEXCONSTE(3.74299477502370467087e+01, 0x4004, 0x95b84439L, 0x19070ea9L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.80143985094819840000e+16, 0x4035, 0x80000000L, 0x00000000L), HEXCONSTE(3.81230949307969920192e+01, 0x4004, 0x987e0c98L, 0xf84e4c90L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(3.60287970189639680000e+16, 0x4036, 0x80000000L, 0x00000000L), HEXCONSTE(3.88162421113569373263e+01, 0x4004, 0x9b43d4f8L, 0xd7958a76L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(7.20575940379279360000e+16, 0x4037, 0x80000000L, 0x00000000L), HEXCONSTE(3.95093892919168826368e+01, 0x4004, 0x9e099d58L, 0xb6dcc85dL), 0 },
	{ __LINE__, HEXCONSTE(1.44115188075855872000e+17, 0x4038, 0x80000000L, 0x00000000L), HEXCONSTE(4.02025364724768279473e+01, 0x4004, 0xa0cf65b8L, 0x96240644L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(2.88230376151711744000e+17, 0x4039, 0x80000000L, 0x00000000L), HEXCONSTE(4.08956836530367732543e+01, 0x4004, 0xa3952e18L, 0x756b442aL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(5.76460752303423488000e+17, 0x403a, 0x80000000L, 0x00000000L), HEXCONSTE(4.15888308335967185649e+01, 0x4004, 0xa65af678L, 0x54b28211L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.26765060022822940150e+30, 0x4063, 0x80000000L, 0x00000000L), HEXCONSTE(7.00078652365544762542e+01, 0x4005, 0x8c0406e9L, 0x8b8db602L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(8.94159862326282983622e+01, 0x4005, 0xb2d4fc25L, 0xc173179fL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(3.27339060789614187001e+150, 0x41f3, 0x80000000L, 0x00000000L), HEXCONSTE(3.47266737460532600029e+02, 0x4007, 0xada22473L, 0xfecd848fL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(8.94159862326282983622e+01, 0x4005, 0xb2d4fc25L, 0xc173179fL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.79769313486231570815e+308, 0x43fe, 0xffffffffL, 0xfffff800L), HEXCONSTE(7.10475860073943942030e+02, 0x4008, 0xb19e747dL, 0xcfc3ed88L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.41246703213942603684e+1505, 0x5387, 0x80000000L, 0x00000000L), HEXCONSTE(3.46642904998028649244e+03, 0x400a, 0xd8a6dd63L, 0x831ae0feL), 0 },
	{ __LINE__, HEXCONSTE(1.50249338150024414062e+00, 0x3fff, 0xc051b400L, 0x00000000L), HEXCONSTE(9.64650470073551659183e-01, 0x3ffe, 0xf6f3554dL, 0x097450e3L), 0 },
	{ __LINE__, HEXCONSTE(1.04536819458007812500e+00, 0x3fff, 0x85cea000L, 0x00000000L), HEXCONSTE(3.00097449950904218030e-01, 0x3ffd, 0x99a65f7aL, 0x4de409e7L), 0 },
	{ __LINE__, HEXCONSTE(1.04536807537078857422e+00, 0x3fff, 0x85ce9f00L, 0x00000000L), HEXCONSTE(3.00097058615722329271e-01, 0x3ffd, 0x99a65258L, 0xc2b99f4eL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.04536811256696071659e+00, 0x3fff, 0x85ce9f4fL, 0xe0cfd800L), HEXCONSTE(3.00097180721789482755e-01, 0x3ffd, 0x99a65671L, 0xa4ce7055L), 0 },
	{ __LINE__, HEXCONSTE(1.06998765468597412109e+00, 0x3fff, 0x88f55b00L, 0x00000000L), HEXCONSTE(3.71984349086711841079e-01, 0x3ffd, 0xbe74bb8bL, 0xe70d7e73L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.06249487400054931641e+00, 0x3fff, 0x87ffd500L, 0x00000000L), HEXCONSTE(3.51723112590137885661e-01, 0x3ffd, 0xb4150d43L, 0xa4d8ffbfL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.02560520172119140625e+00, 0x3fff, 0x83470800L, 0x00000000L), HEXCONSTE(2.25817052878548658456e-01, 0x3ffc, 0xe73c95e3L, 0xf849d514L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.02560508251190185547e+00, 0x3fff, 0x83470700L, 0x00000000L), HEXCONSTE(2.25816529435895013995e-01, 0x3ffc, 0xe73c72c3L, 0x4b26db49L), 0 },
	{ __LINE__, HEXCONSTE(1.02560512955856486528e+00, 0x3fff, 0x83470765L, 0x082d3000L), HEXCONSTE(2.25816736015833490663e-01, 0x3ffc, 0xe73c80a0L, 0x4f5457d0L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(2.55179643630981445312e+00, 0x4000, 0xa350a200L, 0x00000000L), HEXCONSTE(1.58913111734422241028e+00, 0x3fff, 0xcb68a601L, 0x0651e000L), 0 },
	{ __LINE__, HEXCONSTE(9.38031431680000000000e+10, 0x4023, 0xaeb8d300L, 0x00000000L), HEXCONSTE(2.59576113822108442974e+01, 0x4003, 0xcfa93028L, 0x06fbc400L), 0 },
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(8.94159862326282983622e+01, 0x4005, 0xb2d4fc25L, 0xc173179fL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(6.36058900518228837402e+86, 0x411f, 0xa3b51e21L, 0xebf6f000L), HEXCONSTE(2.00565586161989500624e+02, 0x4006, 0xc890ca41L, 0x34d0a800L), 0 },
	{ __LINE__, HEXCONSTE(1.25187244415283203125e+01, 0x4002, 0xc84cb200L, 0x00000000L), HEXCONSTE(3.21877361141696921717e+00, 0x4000, 0xce006308L, 0x90e06106L), 0 },
	{ __LINE__, HEXCONSTE(1.25187234878540039062e+01, 0x4002, 0xc84cb100L, 0x00000000L), HEXCONSTE(3.21877353499291883349e+00, 0x4000, 0xce0062b6L, 0x8197edb4L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.25187243064444295726e+01, 0x4002, 0xc84cb1dbL, 0xbd1b1000L), HEXCONSTE(3.21877360059182948682e+00, 0x4000, 0xce0062fcL, 0xf148e400L), 0 },
	{ __LINE__, HEXCONSTE(1.02786588668823242188e+00, 0x3fff, 0x83911c00L, 0x00000000L), HEXCONSTE(2.35530982721737767877e-01, 0x3ffc, 0xf12f08afL, 0xf03c3c5dL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.02786576747894287109e+00, 0x3fff, 0x83911b00L, 0x00000000L), HEXCONSTE(2.35530481240692454633e-01, 0x3ffc, 0xf12ee708L, 0x8f4608c6L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.02786577775871390550e+00, 0x3fff, 0x83911b16L, 0x135d2800L), HEXCONSTE(2.35530524484935000647e-01, 0x3ffc, 0xf12ee9efL, 0x7d76b035L), 0 },
	{ __LINE__, HEXCONSTE(1.45045948028564453125e+00, 0x3fff, 0xb9a8a800L, 0x00000000L), HEXCONSTE(9.16728199990045994404e-01, 0x3ffe, 0xeaaeb306L, 0x4737caceL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.10747337341308593750e+00, 0x3fff, 0x8dc1b000L, 0x00000000L), HEXCONSTE(4.59568541107771539093e-01, 0x3ffd, 0xeb4c915cL, 0xa8184c0cL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.03041589260101318359e+00, 0x3fff, 0x83e4ab00L, 0x00000000L), HEXCONSTE(2.46020094112509415805e-01, 0x3ffc, 0xfbecb109L, 0x7cfff0c2L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.09388625621795654297e+00, 0x3fff, 0x8c047700L, 0x00000000L), HEXCONSTE(4.30006646886303414582e-01, 0x3ffd, 0xdc29d4caL, 0xe0eb1062L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.06376290321350097656e+00, 0x3fff, 0x88296200L, 0x00000000L), HEXCONSTE(3.55236755318221097608e-01, 0x3ffd, 0xb5e1978cL, 0xdb9a9326L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(8.94159862326282983622e+01, 0x4005, 0xb2d4fc25L, 0xc173179fL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.79769313486231570815e+308, 0x43fe, 0xffffffffL, 0xfffff800L), HEXCONSTE(7.10475860073943942030e+02, 0x4008, 0xb19e747dL, 0xcfc3ed88L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.18973149535723176502e+4932, 0x7ffe, 0xffffffffL, 0xffffffffL), HEXCONSTE(1.13572165534747038951e+04, 0x400c, 0xb174ddc0L, 0x31aec0eaL), 0 },
};

int main(int argc, char **argv)
{
	int status;
	
	status = 0;
	
	test_init(argc, argv);
	
	status |= test_table_f_f(facosh_data, ARRAY_SIZE(facosh_data), __FILE__);
	
	return status ? EXIT_FAILURE : EXIT_SUCCESS;
}