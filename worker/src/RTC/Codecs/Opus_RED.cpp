#define MS_CLASS "RTC::Codecs::Opus_RED"
// #define MS_LOG_DEV_LEVEL 3

#include "RTC/Codecs/Opus_RED.hpp"
#include "Logger.hpp"

namespace RTC
{
	namespace Codecs
	{
		/* Class methods. */

		Opus_RED::PayloadDescriptor* Opus_RED::Parse(const uint8_t* data, size_t len)
		{
			MS_TRACE();

			std::unique_ptr<PayloadDescriptor> payloadDescriptor(new PayloadDescriptor());

			return payloadDescriptor.release();
		}

		void Opus_RED::ProcessRtpPacket(RTC::RtpPacket* packet)
		{
			MS_TRACE();

			auto* data = packet->GetPayload();
			auto len   = packet->GetPayloadLength();

			PayloadDescriptor* payloadDescriptor = Opus_RED::Parse(data, len);

			auto* payloadDescriptorHandler = new PayloadDescriptorHandler(payloadDescriptor);

			packet->SetPayloadDescriptorHandler(payloadDescriptorHandler);
		}

		/* Instance methods. */

		void Opus_RED::PayloadDescriptor::Dump() const
		{
			MS_TRACE();

			MS_DUMP("<PayloadDescriptor>");
			MS_DUMP("</PayloadDescriptor>");
		}

		Opus_RED::PayloadDescriptorHandler::PayloadDescriptorHandler(
		  Opus_RED::PayloadDescriptor* payloadDescriptor)
		{
			MS_TRACE();

			this->payloadDescriptor.reset(payloadDescriptor);
		}

		bool Opus_RED::PayloadDescriptorHandler::Process(
		  RTC::Codecs::EncodingContext* encodingContext, uint8_t* data, bool& /*marker*/)
		{
			MS_TRACE();

			auto* context = static_cast<RTC::Codecs::Opus_RED::EncodingContext*>(encodingContext);

			return true;
		};
	} // namespace Codecs
} // namespace RTC
