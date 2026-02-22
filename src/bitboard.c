/**
 * @file bitboard.c
 * @brief This source file contains the logic for pre-defined functions in
 * bitboard.h
 *
 * @author JJG
 * @date 02/21/2026
 */
#include <stdio.h>

#include "bitboard.h"
#include "bitboard_internal.h"

// Getter functions

bool
BitBoard_Get_Bit(BitBoard board, int square) {
  return (board & (1ULL << square));
}

// Setter functions

void
BitBoard_Set_Bit(BitBoard board, int square) {
  board |= (1ULL << square);
}

bool
BitBoard_Pop_Bit(BitBoard board, int square) {
  return BitBoard_Get_Bit(board, square) ? board ^= (1ULL << square) : 0;
}

// Utility functions

BitBoard
Mask_Pawn_Attacks(int square, int side) {
  uint64_t attacks = 0ULL;
  uint64_t board = 0ULL;
  BitBoard_Set_Bit(board, square);
  if (!side) {
    attacks |= (board >> 7);
  } else {
    attacks |= (board << 7);
  }
  return attacks;
}

void
BitBoard_Print(BitBoard board) {
  for (int rank = 0; rank < 8; rank++) {
    for (int file = 0; file < 8; file++) {
      int square = rank * 8 + file;
      if (!file) {
        printf(ROW_LABELS_FMT, 8 - rank);
      }
      printf(SQUARE_FMT, bitboard_get_bit(board, square) ? 1 : 0);
    }
    printf("\n");
  }
  printf("%s", FILE_LABELS);
  printf("Bitboard: %llu\n\n", board);
}
