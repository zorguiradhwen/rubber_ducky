/*
 * StreamHandler.h
 *
 *  Created on: Dec 20, 2020
 *      Author: Radhwen
 */

#ifndef STREAM_STREAMHANDLER_H_
#define STREAM_STREAMHANDLER_H_




typedef enum StreamType_e
{
	WriteStream, ReadStream, ReadWriteStream
}StreamType;

typedef void* StreamObject;

typedef struct Stream_s
{
	StreamObject handler;
	void* hwAddr;
	StreamType type;
	char name[20];
	u8 id;
}Stream;


typedef enum StreamStatus_e
{
	Stream_OK,
	Stream_InitFailure,
	StreamWrite_Err,
	StreamRead_Err,

}StreamStatus;

/*
 * @brief: Initializes all streams used in the project
 *
 */
StreamStatus Stream_init(void);

void Stream_write(StreamHandler* stream);
void Stream_read(StreamHandler* handler);

#define STREAM_WRITE(stream, fmt, ...) Stream_Write(stream);\
printf("Stream: %s\t " fmt, stream->name, __VA_ARGS__);







#endif /* STREAM_STREAMHANDLER_H_ */
