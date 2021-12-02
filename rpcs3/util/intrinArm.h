/* ===-------- intrin.h ---------------------------------------------------===
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *===-----------------------------------------------------------------------===
 
 Functions extracted from on Clang intrin.h file
 */

static __inline__ unsigned char
_bittest(long const *_BitBase, long _BitPos) {
  return (*_BitBase >> _BitPos) & 1;
}

static __inline__ unsigned char
_interlockedbittestandset_acq(long volatile *_BitBase, long _BitPos) {
  long _PrevVal = __atomic_fetch_or(_BitBase, 1l << _BitPos, __ATOMIC_ACQUIRE);
  return (_PrevVal >> _BitPos) & 1;
}
static __inline__ unsigned char
_interlockedbittestandset_nf(long volatile *_BitBase, long _BitPos) {
  long _PrevVal = __atomic_fetch_or(_BitBase, 1l << _BitPos, __ATOMIC_RELAXED);
  return (_PrevVal >> _BitPos) & 1;
}
static __inline__ unsigned char
_interlockedbittestandset_rel(long volatile *_BitBase, long _BitPos) {
  long _PrevVal = __atomic_fetch_or(_BitBase, 1l << _BitPos, __ATOMIC_RELEASE);
  return (_PrevVal >> _BitPos) & 1;
}


static __inline__ char
_InterlockedCompareExchange8_acq(char volatile *_Destination,
                             char _Exchange, char _Comparand) {
  __atomic_compare_exchange(_Destination, &_Comparand, &_Exchange, 0,
                            __ATOMIC_SEQ_CST, __ATOMIC_ACQUIRE);
  return _Comparand;
}
