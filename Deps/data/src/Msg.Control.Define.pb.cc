// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Msg.Control.Define.proto

#include "Msg.Control.Define.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

namespace Cry {
namespace Control {
namespace Define {
}  // namespace Define
}  // namespace Control
}  // namespace Cry
void InitDefaults_Msg_2eControl_2eDefine_2eproto() {
}

constexpr ::google::protobuf::Metadata* file_level_metadata_Msg_2eControl_2eDefine_2eproto = nullptr;
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors_Msg_2eControl_2eDefine_2eproto[2];
constexpr ::google::protobuf::ServiceDescriptor const** file_level_service_descriptors_Msg_2eControl_2eDefine_2eproto = nullptr;
const ::google::protobuf::uint32 TableStruct_Msg_2eControl_2eDefine_2eproto::offsets[1] = {};
static constexpr ::google::protobuf::internal::MigrationSchema* schemas = nullptr;
static constexpr ::google::protobuf::Message* const* file_default_instances = nullptr;

::google::protobuf::internal::AssignDescriptorsTable assign_descriptors_table_Msg_2eControl_2eDefine_2eproto = {
  {}, AddDescriptors_Msg_2eControl_2eDefine_2eproto, "Msg.Control.Define.proto", schemas,
  file_default_instances, TableStruct_Msg_2eControl_2eDefine_2eproto::offsets,
  file_level_metadata_Msg_2eControl_2eDefine_2eproto, 0, file_level_enum_descriptors_Msg_2eControl_2eDefine_2eproto, file_level_service_descriptors_Msg_2eControl_2eDefine_2eproto,
};

const char descriptor_table_protodef_Msg_2eControl_2eDefine_2eproto[] =
  "\n\030Msg.Control.Define.proto\022\022Cry.Control."
  "Define*\\\n\rMemberMessage\022\027\n\023CID_MESSAGE_D"
  "EFAULT\020\000\022\031\n\024CID_MESSAGE_REGISTER\020\200\002\022\027\n\022C"
  "ID_MESSAGE_SIGNIN\020\201\002*\250\002\n\006SignIn\022\026\n\022CID_S"
  "IGNIN_DEFAULT\020\000\022\035\n\031CID_SIGNIN_USERNAME_E"
  "MPTY\020\001\022\035\n\031CID_SIGNIN_PASSWORD_EMPTY\020\002\022\035\n"
  "\031CID_SIGNIN_USERNAME_ERROR\020\003\022\035\n\031CID_SIGN"
  "IN_PASSWORD_ERROR\020\004\022\024\n\020CID_SIGNIN_BANME\020"
  "\005\022\023\n\017CID_SIGNIN_CODE\020\006\022\026\n\022CID_SIGNIN_EXP"
  "IRES\020\007\022\026\n\022CID_SIGNIN_VERSION\020\010\022\025\n\021CID_SI"
  "GNIN_ONLINE\020\t\022\030\n\024CID_SIGNIN_NOT_ERROR\020\nb"
  "\006proto3"
  ;
::google::protobuf::internal::DescriptorTable descriptor_table_Msg_2eControl_2eDefine_2eproto = {
  false, InitDefaults_Msg_2eControl_2eDefine_2eproto, 
  descriptor_table_protodef_Msg_2eControl_2eDefine_2eproto,
  "Msg.Control.Define.proto", &assign_descriptors_table_Msg_2eControl_2eDefine_2eproto, 447,
};

void AddDescriptors_Msg_2eControl_2eDefine_2eproto() {
  static constexpr ::google::protobuf::internal::InitFunc deps[1] =
  {
  };
 ::google::protobuf::internal::AddDescriptors(&descriptor_table_Msg_2eControl_2eDefine_2eproto, deps, 0);
}

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_Msg_2eControl_2eDefine_2eproto = []() { AddDescriptors_Msg_2eControl_2eDefine_2eproto(); return true; }();
namespace Cry {
namespace Control {
namespace Define {
const ::google::protobuf::EnumDescriptor* MemberMessage_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&assign_descriptors_table_Msg_2eControl_2eDefine_2eproto);
  return file_level_enum_descriptors_Msg_2eControl_2eDefine_2eproto[0];
}
bool MemberMessage_IsValid(int value) {
  switch (value) {
    case 0:
    case 256:
    case 257:
      return true;
    default:
      return false;
  }
}

const ::google::protobuf::EnumDescriptor* SignIn_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&assign_descriptors_table_Msg_2eControl_2eDefine_2eproto);
  return file_level_enum_descriptors_Msg_2eControl_2eDefine_2eproto[1];
}
bool SignIn_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace Define
}  // namespace Control
}  // namespace Cry
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
