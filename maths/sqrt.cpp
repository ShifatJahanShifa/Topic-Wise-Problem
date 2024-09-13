//for calculating square root of a large number safely
// ll bs_sqrt(ll x)
// {
//     ll left = 0, right = 2000000000;
//     while (right > left)
//     {
//         ll mid = (left + right) / 2;

//         if (mid * mid > x)
//             right = mid;
//         else
//             left = mid + 1;
//     }
//     return left - 1;
// }
