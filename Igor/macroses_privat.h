#ifndef __MACROSES_MAL_H
#define __MACROSES_MAL_H

#define _SET_STATE(_output, _output_bit) _output |= (1 << _output_bit)

#define _CLEAR_STATE(_output, _output_bit) _output &= (unsigned int)(~(1 << _output_bit))

#endif
