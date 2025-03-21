#include "structs.h"

const char* _va(const char* format, ...)
{
	char _buf[2048];
	va_list ap;

	va_start(ap, format);
	vsnprintf(_buf, 2048, format, ap);
	_buf[2047] = 0;
	return _buf;
}

#pragma region //msg_t

unsigned __int64 MSG_ReadInt64(const msg_t* msg) {
	auto func = reinterpret_cast<unsigned __int64(*)(const msg_t*)>(0x1412B9270_g);
	return func(msg);
}

void MSG_WriteInt64(const msg_t* msg, const unsigned __int64 value) {
	auto func = reinterpret_cast<void(*)(const msg_t*, const unsigned __int64)>(0x1412BA7F0_g);
	func(msg, value);
}

#pragma endregion


//#pragma region //XUID
//
//void XUID::Deserialize(const msg_t* msg) {
//	this->m_id = MSG_ReadInt64(msg);
//}
//
//void XUID::Serialize(const msg_t* msg) {
//	MSG_WriteInt64(msg, this->m_id);
//}
//
////XUID* XUID::FromHexString(const char* xuidString) {
////	this->m_id = I_atoui64_hex(xuidString);
////	return this;
////}
//
//XUID* XUID::FromMsg(const msg_t* msg) {
//	this->m_id = MSG_ReadInt64(msg);
//	return this;
//}
//
////XUID* XUID::FromString(const char* xuidString) {
////	this->m_id = I_atoui64(xuidString);
////	return this;
////}
//
//XUID* XUID::FromUInt64(unsigned __int64 id) {
//	this->m_id = id;
//	return this;
//}
//
//XUID* XUID::FromUniversalId(unsigned __int64 id) {
//	this->m_id = id;
//	return this;
//}
//
//unsigned __int64 XUID::GetUniversalId() {
//	return this->m_id;
//}
//
//bool XUID::IsNull() {
//	return this->m_id == 0;
//}
//
//bool XUID::IsValid() {
//	return this->m_id != 0;
//}
//
//XUID* XUID::NullXUID() {
//	this->m_id = 0;
//	return this;
//}
//
//XUID* XUID::RandomXUID() {
//	this->m_id = 0;
//	this->m_id = randomULongLong(1, 0x7FFFFFFF);
//	return this;
//}
//
//const char* XUID::ToDevString() {
//	return _va("%zu", this->m_id);
//}
//
//const char* XUID::ToHexString() {
//	return _va("%zx", this->m_id);
//}
//
//const char* XUID::ToString() {
//	return _va("%zu", this->m_id);
//}
//
//bool XUID::operator !=(const XUID* xuid) {
//	return this->m_id != xuid->m_id;
//}
//
//XUID* XUID::operator =(const XUID* xuid) {
//	this->m_id = xuid->m_id;
//	return this;
//}
//
//bool XUID::operator ==(const XUID* xuid) {
//	return this->m_id == xuid->m_id;
//}
//
//#pragma endregion


ClActiveClient* ms_activeClients;

clientUIActive_t* clientUIActives;

gentity_s* g_entities;
