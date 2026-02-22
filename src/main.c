#include <stdbool.h>
#include <stdlib.h>

#include "chapi.h"

int
main(int argc, char* argv[]) {
  int rc = EXIT_SUCCESS;
  uint64_t board = 0ULL;
  BitBoard_Print(Mask_Pawn_Attacks(H4, WHITE));
  for (int rank = 0; rank <8; rank++) {
    for (int file = 0; file <8; file++) {
      int square = rank * 8 + file;
      if (file != 7)
        BitBoard_Set_Bit(board, square);
    }
  }
  BitBoard_Print(board);
  return rc;
}
