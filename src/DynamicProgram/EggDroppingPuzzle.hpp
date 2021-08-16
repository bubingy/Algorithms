#include <vector>

/// <summary>
/// solve egg dropping puzzle.
/// </summary>
/// <param name="num_of_eggs">number of eggs.</param>
/// <param name="num_of_floors">number of floors</param>
/// <returns></returns>
size_t
EggDropping(size_t num_of_eggs, size_t num_of_floors)
{
    if (num_of_floors == 1 || num_of_floors == 0)
        return num_of_floors;

    if (num_of_eggs == 1)
        return num_of_floors;

    size_t min = num_of_floors + 1;
    size_t res;

    for (size_t x = 1; x <= num_of_floors; x++) {
        res = std::max(
            EggDropping(num_of_eggs - 1, x - 1),
            EggDropping(num_of_eggs, num_of_floors - x));
        if (res < min)
            min = res;
    }

    return min + 1;
};