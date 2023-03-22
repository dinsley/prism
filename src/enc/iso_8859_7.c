#include "yp_encoding.h"

// Each element of the following table contains a bitfield that indicates a
// piece of information about the corresponding ISO-8859-7 character.
static unsigned char yp_encoding_iso_8859_7_table[256] = {
  //  0      1      2      3      4      5      6      7      8      9      A      B      C      D      E      F
  0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, // 0x
  0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, // 1x
  0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, // 2x
  0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b010, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, // 3x
  0b000, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, // 4x
  0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b000, 0b000, 0b000, 0b000, 0b000, // 5x
  0b000, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, // 6x
  0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b000, 0b000, 0b000, 0b000, 0b000, // 7x
  0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, // 8x
  0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, // 9x
  0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b000, // Ax
  0b000, 0b000, 0b000, 0b000, 0b000, 0b000, 0b111, 0b000, 0b111, 0b111, 0b111, 0b000, 0b111, 0b000, 0b111, 0b111, // Bx
  0b011, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, // Cx
  0b111, 0b111, 0b000, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b011, 0b011, 0b011, 0b011, // Dx
  0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, // Ex
  0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b011, 0b000, // Fx
};

size_t
yp_encoding_iso_8859_7_char_width(const char *c) {
  return 1;
}

size_t
yp_encoding_iso_8859_7_alpha_char(const char *c) {
  const unsigned char v = *c;
  return (yp_encoding_iso_8859_7_table[v] & YP_ENCODING_ALPHABETIC_BIT) ? 1 : 0;
}

size_t
yp_encoding_iso_8859_7_alnum_char(const char *c) {
  const unsigned char v = *c;
  return (yp_encoding_iso_8859_7_table[v] & YP_ENCODING_ALPHANUMERIC_BIT) ? 1 : 0;
}

bool
yp_encoding_iso_8859_7_isupper_char(const char *c) {
  const unsigned char v = *c;
  return (yp_encoding_iso_8859_7_table[v] & YP_ENCODING_UPPERCASE_BIT) ? true : false;
}
