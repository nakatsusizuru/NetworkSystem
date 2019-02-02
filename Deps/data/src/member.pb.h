// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: member.proto

#ifndef PROTOBUF_INCLUDED_member_2eproto
#define PROTOBUF_INCLUDED_member_2eproto

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
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_member_2eproto

// Internal implementation detail -- do not use these members.
struct TableStruct_member_2eproto {
  static const ::google::protobuf::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors_member_2eproto();
namespace Cry {
namespace Signal {
class Login;
class LoginDefaultTypeInternal;
extern LoginDefaultTypeInternal _Login_default_instance_;
class Register;
class RegisterDefaultTypeInternal;
extern RegisterDefaultTypeInternal _Register_default_instance_;
}  // namespace Signal
}  // namespace Cry
namespace google {
namespace protobuf {
template<> ::Cry::Signal::Login* Arena::CreateMaybeMessage<::Cry::Signal::Login>(Arena*);
template<> ::Cry::Signal::Register* Arena::CreateMaybeMessage<::Cry::Signal::Register>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace Cry {
namespace Signal {

// ===================================================================

class Register final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Cry.Signal.Register) */ {
 public:
  Register();
  virtual ~Register();

  Register(const Register& from);

  inline Register& operator=(const Register& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Register(Register&& from) noexcept
    : Register() {
    *this = ::std::move(from);
  }

  inline Register& operator=(Register&& from) noexcept {
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
  static const Register& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Register* internal_default_instance() {
    return reinterpret_cast<const Register*>(
               &_Register_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Register* other);
  friend void swap(Register& a, Register& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Register* New() const final {
    return CreateMaybeMessage<Register>(nullptr);
  }

  Register* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Register>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Register& from);
  void MergeFrom(const Register& from);
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
  void InternalSwap(Register* other);
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

  // bytes username = 1;
  void clear_username();
  static const int kUsernameFieldNumber = 1;
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

  // bytes password = 2;
  void clear_password();
  static const int kPasswordFieldNumber = 2;
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

  // @@protoc_insertion_point(class_scope:Cry.Signal.Register)
 private:
  class HasBitSetters;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr username_;
  ::google::protobuf::internal::ArenaStringPtr password_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_member_2eproto;
};
// -------------------------------------------------------------------

class Login final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Cry.Signal.Login) */ {
 public:
  Login();
  virtual ~Login();

  Login(const Login& from);

  inline Login& operator=(const Login& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Login(Login&& from) noexcept
    : Login() {
    *this = ::std::move(from);
  }

  inline Login& operator=(Login&& from) noexcept {
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
  static const Login& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Login* internal_default_instance() {
    return reinterpret_cast<const Login*>(
               &_Login_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(Login* other);
  friend void swap(Login& a, Login& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Login* New() const final {
    return CreateMaybeMessage<Login>(nullptr);
  }

  Login* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Login>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Login& from);
  void MergeFrom(const Login& from);
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
  void InternalSwap(Login* other);
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

  // bytes username = 1;
  void clear_username();
  static const int kUsernameFieldNumber = 1;
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

  // bytes password = 2;
  void clear_password();
  static const int kPasswordFieldNumber = 2;
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

  // @@protoc_insertion_point(class_scope:Cry.Signal.Login)
 private:
  class HasBitSetters;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr username_;
  ::google::protobuf::internal::ArenaStringPtr password_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_member_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Register

// bytes username = 1;
inline void Register::clear_username() {
  username_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Register::username() const {
  // @@protoc_insertion_point(field_get:Cry.Signal.Register.username)
  return username_.GetNoArena();
}
inline void Register::set_username(const ::std::string& value) {
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Cry.Signal.Register.username)
}
#if LANG_CXX11
inline void Register::set_username(::std::string&& value) {
  
  username_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Cry.Signal.Register.username)
}
#endif
inline void Register::set_username(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Cry.Signal.Register.username)
}
inline void Register::set_username(const void* value, size_t size) {
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Cry.Signal.Register.username)
}
inline ::std::string* Register::mutable_username() {
  
  // @@protoc_insertion_point(field_mutable:Cry.Signal.Register.username)
  return username_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Register::release_username() {
  // @@protoc_insertion_point(field_release:Cry.Signal.Register.username)
  
  return username_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Register::set_allocated_username(::std::string* username) {
  if (username != nullptr) {
    
  } else {
    
  }
  username_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), username);
  // @@protoc_insertion_point(field_set_allocated:Cry.Signal.Register.username)
}

// bytes password = 2;
inline void Register::clear_password() {
  password_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Register::password() const {
  // @@protoc_insertion_point(field_get:Cry.Signal.Register.password)
  return password_.GetNoArena();
}
inline void Register::set_password(const ::std::string& value) {
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Cry.Signal.Register.password)
}
#if LANG_CXX11
inline void Register::set_password(::std::string&& value) {
  
  password_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Cry.Signal.Register.password)
}
#endif
inline void Register::set_password(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Cry.Signal.Register.password)
}
inline void Register::set_password(const void* value, size_t size) {
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Cry.Signal.Register.password)
}
inline ::std::string* Register::mutable_password() {
  
  // @@protoc_insertion_point(field_mutable:Cry.Signal.Register.password)
  return password_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Register::release_password() {
  // @@protoc_insertion_point(field_release:Cry.Signal.Register.password)
  
  return password_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Register::set_allocated_password(::std::string* password) {
  if (password != nullptr) {
    
  } else {
    
  }
  password_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), password);
  // @@protoc_insertion_point(field_set_allocated:Cry.Signal.Register.password)
}

// -------------------------------------------------------------------

// Login

// bytes username = 1;
inline void Login::clear_username() {
  username_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Login::username() const {
  // @@protoc_insertion_point(field_get:Cry.Signal.Login.username)
  return username_.GetNoArena();
}
inline void Login::set_username(const ::std::string& value) {
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Cry.Signal.Login.username)
}
#if LANG_CXX11
inline void Login::set_username(::std::string&& value) {
  
  username_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Cry.Signal.Login.username)
}
#endif
inline void Login::set_username(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Cry.Signal.Login.username)
}
inline void Login::set_username(const void* value, size_t size) {
  
  username_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Cry.Signal.Login.username)
}
inline ::std::string* Login::mutable_username() {
  
  // @@protoc_insertion_point(field_mutable:Cry.Signal.Login.username)
  return username_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Login::release_username() {
  // @@protoc_insertion_point(field_release:Cry.Signal.Login.username)
  
  return username_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Login::set_allocated_username(::std::string* username) {
  if (username != nullptr) {
    
  } else {
    
  }
  username_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), username);
  // @@protoc_insertion_point(field_set_allocated:Cry.Signal.Login.username)
}

// bytes password = 2;
inline void Login::clear_password() {
  password_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Login::password() const {
  // @@protoc_insertion_point(field_get:Cry.Signal.Login.password)
  return password_.GetNoArena();
}
inline void Login::set_password(const ::std::string& value) {
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Cry.Signal.Login.password)
}
#if LANG_CXX11
inline void Login::set_password(::std::string&& value) {
  
  password_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Cry.Signal.Login.password)
}
#endif
inline void Login::set_password(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Cry.Signal.Login.password)
}
inline void Login::set_password(const void* value, size_t size) {
  
  password_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Cry.Signal.Login.password)
}
inline ::std::string* Login::mutable_password() {
  
  // @@protoc_insertion_point(field_mutable:Cry.Signal.Login.password)
  return password_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Login::release_password() {
  // @@protoc_insertion_point(field_release:Cry.Signal.Login.password)
  
  return password_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Login::set_allocated_password(::std::string* password) {
  if (password != nullptr) {
    
  } else {
    
  }
  password_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), password);
  // @@protoc_insertion_point(field_set_allocated:Cry.Signal.Login.password)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Signal
}  // namespace Cry

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // PROTOBUF_INCLUDED_member_2eproto