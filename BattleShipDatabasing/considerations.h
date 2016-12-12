#ifndef CONSIDERATIONS_H
#define CONSIDERATIONS_H

#endif // CONSIDERATIONS_H

/*
*   1) For Optamization: Consider changing all for loop integer iterators into unsigned integers.
*   Since they never go into negative numbers, there is no need to take up the extra space.
*   Not a major optomization.
*
*   2) For better randomization: Change all random seeds to be seeded with millisecond time insted of time(null)
*   which is just seconds. The seconds seed can happen twice since computers run functions so fast,
*   resulting in the same seed number.
*
*
*
*
*
*
*
*
*
*/
