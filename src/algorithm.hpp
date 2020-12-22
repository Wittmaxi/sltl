#include <vector>

namespace sltl
{
    /*
     *  all_of: Test condition on all elements in range.
     */
    template <class InputIterator, class UnaryPredicate>
          bool all_of (InputIterator first, InputIterator last, UnaryPredicate pred) {
              for (;first != last;first++) {
                  if (!pred(*first)) {
                      return false;
                  }
              }
              return true;
          }


    /*
     *  any_of: Test if any element in range fulfills condition
     */
    template <class InputIterator, class UnaryPredicate>
          bool any_of (InputIterator first, InputIterator last, UnaryPredicate pred) {
              for (;first != last;first++) {
                  if (pred(*first)) {
                      return true;
                  }
              }
              return false;
          }


    /*
     *  count: Count appearances of value in range.
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
