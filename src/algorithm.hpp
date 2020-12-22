#include <vector>

namespace sltl
{
    /*
     *  count: Count appearances of value in range
     */
    template <class InputIterator, class T>
        typename std::iterator_traits<InputIterator>::difference_type
        count (InputIterator first, InputIterator last, const T& val) {
            typename std::iterator_traits<InputIterator>::difference_type ret = 0;
            while (first != last) {
                if (*first == val) {
                    ret++;
                }
                first++;
            }
            return ret;
        }
}
