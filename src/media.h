#pragma once

#include <cstdint>
#include <memory>

enum MediaType
{
	H264 = 96,
	AAC  = 37, 
	NONE
};	

enum FrameType
{
	VIDEO_FRAME_I = 0x01,	  
	VIDEO_FRAME_P = 0x02,
	VIDEO_FRAME_B = 0x03,    
	AUDIO_FRAME   = 0x11,   
};

struct MediaFrame
{	
	MediaFrame(uint32_t size = 0)
		:buffer(new uint8_t[size + 1])
	{
		this->size = size;
		type = 0;
		timestamp = 0;
	}

	std::shared_ptr<uint8_t> buffer; /* 帧数据 */
	uint32_t size;				     /* 帧大小 */
	uint8_t  type;				     /* 帧类型 */	
	uint32_t timestamp;		  	     /* 时间戳 */
};