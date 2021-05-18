#include "circular_buffer.h"

/** 
  * @brief  Initialize a CircularBuffer.
  * @param  buff: CircularBuffer to initialize
  * @param  data: pointer to the memory area where CircularBuffer data will
  *          be stored.
  * @param  dim: buffer dimension.
  * @note   Size of the memory area allocated for CircularBuffer data 
  *          element must enough to contain dim uint8_t elements.
  * @retval None.
  */
void CircularBuffer_Init(CircularBuffer* buff, uint8_t* data, uint32_t dim)
{
    buff->write_index = 0;
    buff->read_index = 0;
    buff->dimension = dim;
    buff->data = data;
}

/** 
  * @brief  Check if a CircularBuffer is full.
  * @param  buff: CircularBuffer to check.
  * @retval The function returns:
  *           - 1: if CircularBuffer is full;
  *           - 0: otherwise.
  */
uint8_t CircularBuffer_IsFull(CircularBuffer* buff)
{
    return (((buff->write_index + 1) % buff->dimension) == buff->read_index);
}

/** 
  * @brief  Check if a CircularBuffer is empty.
  * @param  buff: CircularBuffer to check.
  * @retval The function returns:
  *           - 1: if CircularBuffer is empty;
  *           - 0: otherwise.
  */
uint8_t CircularBuffer_IsEmpty(CircularBuffer* buff)
{
    return (buff->read_index == buff->write_index);
}

/** 
  * @brief  Add an element to the CircularBuffer.
  * @param  buff: CircularBuffer where data will be written. 
  * @param  item: data to add at the CircularBuffer. 
  * @retval The function returns:
  *           - 1: if item is added to the CircularBuffer;
  *           - 0: if not (buffer full).
  */
uint8_t CircularBuffer_Write(CircularBuffer* buff, uint8_t item)
{
    if(!CircularBuffer_IsFull(buff))
    {
        buff->data[buff->write_index] = item;
        buff->write_index++;
        buff->write_index %= buff->dimension;
        return 1;
    }
    else
        return 0;
}

/** 
  * @brief  Extract an element from CircularBuffer.
  * @param  buff: CircularBuffer to be read. 
  * @param  item: pointer to the memory area where the read data will be
 *           stored. 
  * @retval The function returns:
  *           - 1: if item is extracted from the CircularBuffer;
  *           - 0: if not (buffer empty).
  */
uint8_t CircularBuffer_Read(CircularBuffer* buff, uint8_t* item)
{
    if(!CircularBuffer_IsEmpty(buff))
    {
        *item = buff->data[buff->read_index];
        buff->read_index++;
        buff->read_index %= buff->dimension;
        return 1;
    }
    else
        return 0;
}
