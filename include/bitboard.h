/**
 * @file bitboard.h
 * @brief This header file defines public functions related to Bit Boards
 *
 * @author JJG
 * @date 02/21/2026
 */
#ifndef BITBOARD_H
#define BITBOARD_H

#include <stdint.h>
#include <stdbool.h>

typedef struct BitBoard;

// Getter functions

bool BitBoard_Get_Bit(BitBoard board, int square);

// Setter functions

void BitBoard_Set_Bit(BitBoard board, int square);

bool BitBoard_Pop_Bit(BitBoard board, int square);

// Utility functions

BitBoard Mask_Pawn_Attacks(int square, int side);

void BitBoard_Print(BitBoard board);

#endif
