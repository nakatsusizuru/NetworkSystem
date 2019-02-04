// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Msg.Control.Member.proto

#ifndef PROTOBUF_INCLUDED_Msg_2eControl_2eMember_2eproto
#define PROTOBUF_INCLUDED_Msg_2eControl_2eMember_2eproto

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
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "Msg.Control.Define.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Msg_2eControl_2eMember_2eproto

// Internal implementation detail -- do not use these members.
struct TableStruct_Msg_2eControl_2eMember_2eproto {
  static const ::google::protobuf::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors_Msg_2eControl_2eMember_2eproto();
namespace Cry {
namespace Control {
namespace Member {
class MsgRegisterRequest;
class MsgRegisterRequestDefaultTypeInternal;
extern MsgRegisterRequestDefaultTypeInternal _MsgRegisterRequest_default_instance_;
class MsgSignInRequest;
class MsgSignInRequestDefaultTypeInternal;
extern MsgSignInRequestDefaultTypeInternal _MsgSignInRequest_default_instance_;
class MsgSignInResponse;
class MsgSignInResponseDefaultTypeInternal;
extern MsgSignInResponseDefaultTypeInternal _MsgSignInResponse_default_instance_;
}  // namespace Member
}  // namespace Control
}  // namespace Cry
namespace google {
namespace protobuf {
template<> ::Cry::Control::Member::MsgRegisterRequest* Arena::CreateMaybeMessage<::Cry::Control::Member::MsgRegisterRequest>(Arena*);
template<> ::Cry::Control::Member::MsgSignInRequest* Arena::CreateMaybeMessage<::Cry::Control::Member::MsgSignInRequest>(Arena*);
template<> ::Cry::Control::Member::MsgSignInResponse* Arena::CreateMaybeMessage<::Cry::Control::Member::MsgSignInResponse>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace Cry {
namespace Control {
namespace Member {

// ===================================================================

class MsgRegisterRequest final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Cry.Control.Member.MsgRegisterRequest) */ {
 public:
  MsgRegisterRequest();
  virtual ~MsgRegisterRequest();

  MsgRegisterRequest(const MsgRegisterRequest& from);

  inline MsgRegisterRequest& operator=(const MsgRegisterRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MsgRegisterRequest(MsgRegisterRequest&& from) noexcept
    : MsgRegisterRequest() {
    *this = ::std::move(from);
  }

  inline MsgRegisterRequest& operator=(MsgRegisterRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const MsgRegisterRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const MsgRegisterRequest* internal_default_instance() {
    return reinterpret_cast<const MsgRegisterRequest*>(
               &_MsgRegisterRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(MsgRegisterRequest* other);
  friend void swap(MsgRegisterRequest& a, MsgRegisterRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MsgRegisterRequest* New() const final {
    return CreateMaybeMessage<MsgRegisterRequest>(nullptr);
  }

  MsgRegisterRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<MsgRegisterRequest>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const MsgRegisterRequest& from);
  void MergeFrom(const MsgRegisterRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  static const char* _InternalParse(const char* begin, const char* end, void* object, ::google::protobuf::internal::ParseContext* ctx);
  ::google::protobuf::internal::ParseFunc _ParseFunc() const final { return _InternalParse; }
  #else
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(MsgRegisterRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bytes username = 2;
  void clear_username();
  static const int kUsernameFieldNumber = 2;
  const ::std::string& username() const;
  void set_username(const ::std::string& value);
  #if LANG_CXX11
  void set_username(::std::string&& value);
  #endif
  void set_username(const char* value);
  void set_username(const void* value, size_t size);
  ::std::string* mutable_username();
  ::std::string* release_username();
  void set_allocated_username(::std::string* username);

  // bytes password = 3;
  void clear_password();
  static const int kPasswordFieldNumber = 3;
  const ::std::string& password() const;
  void set_password(const ::std::string& value);
  #if LANG_CXX11
  void set_password(::std::string&& value);
  #endif
  void set_password(const char* value);
  void set_password(const void* value, size_t size);
  ::std::string* mutable_password();
  ::std::string* release_password();
  void set_allocated_password(::std::string* password);

  // @@protoc_insertion_point(class_scope:Cry.Control.Member.MsgRegisterRequest)
 private:
  class HasBitSetters;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr username_;
  ::google::protobuf::internal::ArenaStringPtr password_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Msg_2eControl_2eMember_2eproto;
};
// -------------------------------------------------------------------

class MsgSignInRequest final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Cry.Control.Member.MsgSignInRequest) */ {
 public:
  MsgSignInRequest();
  virtual ~MsgSignInRequest();

  MsgSignInRequest(const MsgSignInRequest& from);

  inline MsgSignInRequest& operator=(const MsgSignInRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MsgSignInRequest(MsgSignInRequest&& from) noexcept
    : MsgSignInRequest() {
    *this = ::std::move(from);
  }

  inline MsgSignInRequest& operator=(MsgSignInRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const MsgSignInRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const MsgSignInRequest* internal_default_instance() {
    return reinterpret_cast<const MsgSignInRequest*>(
               &_MsgSignInRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(MsgSignInRequest* other);
  friend void swap(MsgSignInRequest& a, MsgSignInRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MsgSignInRequest* New() const final {
    return CreateMaybeMessage<MsgSignInRequest>(nullptr);
  }

  MsgSignInRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<MsgSignInRequest>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const MsgSignInRequest& from);
  void MergeFrom(const MsgSignInRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  static const char* _InternalParse(const char* begin, const char* end, void* object, ::google::protobuf::internal::ParseContext* ctx);
  ::google::protobuf::internal::ParseFunc _ParseFunc() const final { return _InternalParse; }
  #else
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(MsgSignInRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bytes username = 2;
  void clear_username();
  static const int kUsernameFieldNumber = 2;
  const ::std::string& username() const;
  void set_username(const ::std::string& value);
  #if LANG_CXX11
  void set_username(::std::string&& value);
  #endif
  void set_username(const char* value);
  void set_username(const void* value, size_t size);
  ::std::string* mutable_username();
  ::std::string* release_username();
  void set_allocated_username(::std::string* username);

  // bytes password = 3;
  void clear_password();
  static const int kPasswordFieldNumber = 3;
  const ::std::string& password() const;
  void set_password(const ::std::string& value);
  #if LANG_CXX11
  void set_password(::std::string&& value);
  #endif
  void set_password(const char* value);
  void set_password(const void* value, size_t size);
  ::std::string* mutable_password();
  ::std::string* release_password();
  void set_allocated_password(::std::string* password);

  // uint32 version = 4;
  void clear_version();
  static const int kVersionFieldNumber = 4;
  ::google::protobuf::uint32 version() const;
  void set_version(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:Cry.Control.Member.MsgSignInRequest)
 private:
  class HasBitSetters;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr username_;
  ::google::protobuf::internal::ArenaStringPtr password_;
  ::google::protobuf::uint32 version_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Msg_2eControl_2eMember_2eproto;
};
// -------------------------------------------------------------------

class MsgSignInResponse final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Cry.Control.Member.MsgSignInResponse) */ {
 public:
  MsgSignInResponse();
  virtual ~MsgSignInResponse();

  MsgSignInResponse(const MsgSignInResponse& from);

  inline MsgSignInResponse& operator=(const MsgSignInResponse& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MsgSignInResponse(MsgSignInResponse&& from) noexcept
    : MsgSignInResponse() {
    *this = ::std::move(from);
  }

  inline MsgSignInResponse& operator=(MsgSignInResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const MsgSignInResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const MsgSignInResponse* internal_default_instance() {
    return reinterpret_cast<const MsgSignInResponse*>(
               &_MsgSignInResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(MsgSignInResponse* other);
  friend void swap(MsgSignInResponse& a, MsgSignInResponse& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MsgSignInResponse* New() const final {
    return CreateMaybeMessage<MsgSignInResponse>(nullptr);
  }

  MsgSignInResponse* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<MsgSignInResponse>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const MsgSignInResponse& from);
  void MergeFrom(const MsgSignInResponse& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  static const char* _InternalParse(const char* begin, const char* end, void* object, ::google::protobuf::internal::ParseContext* ctx);
  ::google::protobuf::internal::ParseFunc _ParseFunc() const final { return _InternalParse; }
  #else
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(MsgSignInResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .Cry.Control.Define.SignIn msg = 1;
  void clear_msg();
  static const int kMsgFieldNumber = 1;
  ::Cry::Control::Define::SignIn msg() const;
  void set_msg(::Cry::Control::Define::SignIn value);

  // int32 uid = 2;
  void clear_uid();
  static const int kUidFieldNumber = 2;
  ::google::protobuf::int32 uid() const;
  void set_uid(::google::protobuf::int32 value);

  // uint32 expires = 3;
  void clear_expires();
  static const int kExpiresFieldNumber = 3;
  ::google::protobuf::uint32 expires() const;
  void set_expires(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:Cry.Control.Member.MsgSignInResponse)
 private:
  class HasBitSetters;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  int msg_;
  ::google::protobuf::int32 uid_;
  ::google::protobuf::uint32 expires_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Msg_2eControl_2eMember_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MsgRegisterRequest

// bytes username = 2;
inline void MsgRegisterRequest::clear_username() {
  username_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MsgRegisterRequest::username() const {
  // @@protoc_insertion_point(field_get:Cry.Control.Member.MsgRegisterRequest.username)
  return username_.GetNoArena();
}
inline void MsgRegisterRequest::set_username(const ::std::string& value) {
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Cry.Control.Member.MsgRegisterRequest.username)
}
#if LANG_CXX11
inline void MsgRegisterRequest::set_username(::std::string&& value) {
  
  username_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Cry.Control.Member.MsgRegisterRequest.username)
}
#endif
inline void MsgRegisterRequest::set_username(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Cry.Control.Member.MsgRegisterRequest.username)
}
inline void MsgRegisterRequest::set_username(const void* value, size_t size) {
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Cry.Control.Member.MsgRegisterRequest.username)
}
inline ::std::string* MsgRegisterRequest::mutable_username() {
  
  // @@protoc_insertion_point(field_mutable:Cry.Control.Member.MsgRegisterRequest.username)
  return username_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MsgRegisterRequest::release_username() {
  // @@protoc_insertion_point(field_release:Cry.Control.Member.MsgRegisterRequest.username)
  
  return username_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MsgRegisterRequest::set_allocated_username(::std::string* username) {
  if (username != nullptr) {
    
  } else {
    
  }
  username_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), username);
  // @@protoc_insertion_point(field_set_allocated:Cry.Control.Member.MsgRegisterRequest.username)
}

// bytes password = 3;
inline void MsgRegisterRequest::clear_password() {
  password_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MsgRegisterRequest::password() const {
  // @@protoc_insertion_point(field_get:Cry.Control.Member.MsgRegisterRequest.password)
  return password_.GetNoArena();
}
inline void MsgRegisterRequest::set_password(const ::std::string& value) {
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Cry.Control.Member.MsgRegisterRequest.password)
}
#if LANG_CXX11
inline void MsgRegisterRequest::set_password(::std::string&& value) {
  
  password_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Cry.Control.Member.MsgRegisterRequest.password)
}
#endif
inline void MsgRegisterRequest::set_password(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Cry.Control.Member.MsgRegisterRequest.password)
}
inline void MsgRegisterRequest::set_password(const void* value, size_t size) {
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Cry.Control.Member.MsgRegisterRequest.password)
}
inline ::std::string* MsgRegisterRequest::mutable_password() {
  
  // @@protoc_insertion_point(field_mutable:Cry.Control.Member.MsgRegisterRequest.password)
  return password_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MsgRegisterRequest::release_password() {
  // @@protoc_insertion_point(field_release:Cry.Control.Member.MsgRegisterRequest.password)
  
  return password_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MsgRegisterRequest::set_allocated_password(::std::string* password) {
  if (password != nullptr) {
    
  } else {
    
  }
  password_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), password);
  // @@protoc_insertion_point(field_set_allocated:Cry.Control.Member.MsgRegisterRequest.password)
}

// -------------------------------------------------------------------

// MsgSignInRequest

// bytes username = 2;
inline void MsgSignInRequest::clear_username() {
  username_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MsgSignInRequest::username() const {
  // @@protoc_insertion_point(field_get:Cry.Control.Member.MsgSignInRequest.username)
  return username_.GetNoArena();
}
inline void MsgSignInRequest::set_username(const ::std::string& value) {
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Cry.Control.Member.MsgSignInRequest.username)
}
#if LANG_CXX11
inline void MsgSignInRequest::set_username(::std::string&& value) {
  
  username_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Cry.Control.Member.MsgSignInRequest.username)
}
#endif
inline void MsgSignInRequest::set_username(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Cry.Control.Member.MsgSignInRequest.username)
}
inline void MsgSignInRequest::set_username(const void* value, size_t size) {
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Cry.Control.Member.MsgSignInRequest.username)
}
inline ::std::string* MsgSignInRequest::mutable_username() {
  
  // @@protoc_insertion_point(field_mutable:Cry.Control.Member.MsgSignInRequest.username)
  return username_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MsgSignInRequest::release_username() {
  // @@protoc_insertion_point(field_release:Cry.Control.Member.MsgSignInRequest.username)
  
  return username_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MsgSignInRequest::set_allocated_username(::std::string* username) {
  if (username != nullptr) {
    
  } else {
    
  }
  username_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), username);
  // @@protoc_insertion_point(field_set_allocated:Cry.Control.Member.MsgSignInRequest.username)
}

// bytes password = 3;
inline void MsgSignInRequest::clear_password() {
  password_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MsgSignInRequest::password() const {
  // @@protoc_insertion_point(field_get:Cry.Control.Member.MsgSignInRequest.password)
  return password_.GetNoArena();
}
inline void MsgSignInRequest::set_password(const ::std::string& value) {
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Cry.Control.Member.MsgSignInRequest.password)
}
#if LANG_CXX11
inline void MsgSignInRequest::set_password(::std::string&& value) {
  
  password_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Cry.Control.Member.MsgSignInRequest.password)
}
#endif
inline void MsgSignInRequest::set_password(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Cry.Control.Member.MsgSignInRequest.password)
}
inline void MsgSignInRequest::set_password(const void* value, size_t size) {
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Cry.Control.Member.MsgSignInRequest.password)
}
inline ::std::string* MsgSignInRequest::mutable_password() {
  
  // @@protoc_insertion_point(field_mutable:Cry.Control.Member.MsgSignInRequest.password)
  return password_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MsgSignInRequest::release_password() {
  // @@protoc_insertion_point(field_release:Cry.Control.Member.MsgSignInRequest.password)
  
  return password_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MsgSignInRequest::set_allocated_password(::std::string* password) {
  if (password != nullptr) {
    
  } else {
    
  }
  password_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), password);
  // @@protoc_insertion_point(field_set_allocated:Cry.Control.Member.MsgSignInRequest.password)
}

// uint32 version = 4;
inline void MsgSignInRequest::clear_version() {
  version_ = 0u;
}
inline ::google::protobuf::uint32 MsgSignInRequest::version() const {
  // @@protoc_insertion_point(field_get:Cry.Control.Member.MsgSignInRequest.version)
  return version_;
}
inline void MsgSignInRequest::set_version(::google::protobuf::uint32 value) {
  
  version_ = value;
  // @@protoc_insertion_point(field_set:Cry.Control.Member.MsgSignInRequest.version)
}

// -------------------------------------------------------------------

// MsgSignInResponse

// .Cry.Control.Define.SignIn msg = 1;
inline void MsgSignInResponse::clear_msg() {
  msg_ = 0;
}
inline ::Cry::Control::Define::SignIn MsgSignInResponse::msg() const {
  // @@protoc_insertion_point(field_get:Cry.Control.Member.MsgSignInResponse.msg)
  return static_cast< ::Cry::Control::Define::SignIn >(msg_);
}
inline void MsgSignInResponse::set_msg(::Cry::Control::Define::SignIn value) {
  
  msg_ = value;
  // @@protoc_insertion_point(field_set:Cry.Control.Member.MsgSignInResponse.msg)
}

// int32 uid = 2;
inline void MsgSignInResponse::clear_uid() {
  uid_ = 0;
}
inline ::google::protobuf::int32 MsgSignInResponse::uid() const {
  // @@protoc_insertion_point(field_get:Cry.Control.Member.MsgSignInResponse.uid)
  return uid_;
}
inline void MsgSignInResponse::set_uid(::google::protobuf::int32 value) {
  
  uid_ = value;
  // @@protoc_insertion_point(field_set:Cry.Control.Member.MsgSignInResponse.uid)
}

// uint32 expires = 3;
inline void MsgSignInResponse::clear_expires() {
  expires_ = 0u;
}
inline ::google::protobuf::uint32 MsgSignInResponse::expires() const {
  // @@protoc_insertion_point(field_get:Cry.Control.Member.MsgSignInResponse.expires)
  return expires_;
}
inline void MsgSignInResponse::set_expires(::google::protobuf::uint32 value) {
  
  expires_ = value;
  // @@protoc_insertion_point(field_set:Cry.Control.Member.MsgSignInResponse.expires)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Member
}  // namespace Control
}  // namespace Cry

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // PROTOBUF_INCLUDED_Msg_2eControl_2eMember_2eproto