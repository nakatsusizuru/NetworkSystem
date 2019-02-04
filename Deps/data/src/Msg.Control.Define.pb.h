// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Msg.Control.Define.proto

#ifndef PROTOBUF_INCLUDED_Msg_2eControl_2eDefine_2eproto
#define PROTOBUF_INCLUDED_Msg_2eControl_2eDefine_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3007000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3007000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Msg_2eControl_2eDefine_2eproto

// Internal implementation detail -- do not use these members.
struct TableStruct_Msg_2eControl_2eDefine_2eproto {
  static const ::google::protobuf::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors_Msg_2eControl_2eDefine_2eproto();
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
namespace Cry {
namespace Control {
namespace Define {

enum MemberMessage {
  CID_MESSAGE_DEFAULT = 0,
  CID_MESSAGE_REGISTER = 256,
  CID_MESSAGE_SIGNIN = 257,
  MemberMessage_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::google::protobuf::int32>::min(),
  MemberMessage_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::google::protobuf::int32>::max()
};
bool MemberMessage_IsValid(int value);
const MemberMessage MemberMessage_MIN = CID_MESSAGE_DEFAULT;
const MemberMessage MemberMessage_MAX = CID_MESSAGE_SIGNIN;
const int MemberMessage_ARRAYSIZE = MemberMessage_MAX + 1;

const ::google::protobuf::EnumDescriptor* MemberMessage_descriptor();
inline const ::std::string& MemberMessage_Name(MemberMessage value) {
  return ::google::protobuf::internal::NameOfEnum(
    MemberMessage_descriptor(), value);
}
inline bool MemberMessage_Parse(
    const ::std::string& name, MemberMessage* value) {
  return ::google::protobuf::internal::ParseNamedEnum<MemberMessage>(
    MemberMessage_descriptor(), name, value);
}
enum SignIn {
  CID_SIGNIN_DEFAULT = 0,
  CID_SIGNIN_USERNAME_EMPTY = 1,
  CID_SIGNIN_PASSWORD_EMPTY = 2,
  CID_SIGNIN_USERNAME_ERROR = 3,
  CID_SIGNIN_PASSWORD_ERROR = 4,
  CID_SIGNIN_NOT_ERROR = 5,
  SignIn_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::google::protobuf::int32>::min(),
  SignIn_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::google::protobuf::int32>::max()
};
bool SignIn_IsValid(int value);
const SignIn SignIn_MIN = CID_SIGNIN_DEFAULT;
const SignIn SignIn_MAX = CID_SIGNIN_NOT_ERROR;
const int SignIn_ARRAYSIZE = SignIn_MAX + 1;

const ::google::protobuf::EnumDescriptor* SignIn_descriptor();
inline const ::std::string& SignIn_Name(SignIn value) {
  return ::google::protobuf::internal::NameOfEnum(
    SignIn_descriptor(), value);
}
inline bool SignIn_Parse(
    const ::std::string& name, SignIn* value) {
  return ::google::protobuf::internal::ParseNamedEnum<SignIn>(
    SignIn_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace Define
}  // namespace Control
}  // namespace Cry

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::Cry::Control::Define::MemberMessage> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Cry::Control::Define::MemberMessage>() {
  return ::Cry::Control::Define::MemberMessage_descriptor();
}
template <> struct is_proto_enum< ::Cry::Control::Define::SignIn> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Cry::Control::Define::SignIn>() {
  return ::Cry::Control::Define::SignIn_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // PROTOBUF_INCLUDED_Msg_2eControl_2eDefine_2eproto