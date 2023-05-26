
// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
//
// Code generated by Microsoft (R) AutoRest C++ Code Generator.
// Changes may cause incorrect behavior and will be lost if the code is regenerated.
#pragma once

#include <azure/core/context.hpp>
#include <azure/core/datetime.hpp>
#include <azure/core/etag.hpp>
#include <azure/core/internal/http/pipeline.hpp>
#include <azure/core/io/body_stream.hpp>
#include <azure/core/nullable.hpp>
#include <azure/core/response.hpp>
#include <azure/core/url.hpp>
#include <azure/storage/common/storage_common.hpp>
#include <azure/storage/files/datalake/dll_import_export.hpp>

#include <cstdint>
#include <string>
#include <vector>

namespace Azure { namespace Storage { namespace Files { namespace DataLake {
  namespace _detail {
    /**
     * The version used for the operations to Azure storage services.
     */
    constexpr static const char* ApiVersion = "2021-06-08";
  } // namespace _detail
  namespace Models {
    namespace _detail {
      class PathRenameMode final {
      public:
        PathRenameMode() = default;
        explicit PathRenameMode(std::string value) : m_value(std::move(value)) {}
        bool operator==(const PathRenameMode& other) const { return m_value == other.m_value; }
        bool operator!=(const PathRenameMode& other) const { return !(*this == other); }
        const std::string& ToString() const { return m_value; }
        AZ_STORAGE_FILES_DATALAKE_DLLEXPORT const static PathRenameMode Legacy;
        AZ_STORAGE_FILES_DATALAKE_DLLEXPORT const static PathRenameMode Posix;

      private:
        std::string m_value;
      };
      class PathSetAccessControlListRecursiveMode final {
      public:
        PathSetAccessControlListRecursiveMode() = default;
        explicit PathSetAccessControlListRecursiveMode(std::string value)
            : m_value(std::move(value))
        {
        }
        bool operator==(const PathSetAccessControlListRecursiveMode& other) const
        {
          return m_value == other.m_value;
        }
        bool operator!=(const PathSetAccessControlListRecursiveMode& other) const
        {
          return !(*this == other);
        }
        const std::string& ToString() const { return m_value; }
        AZ_STORAGE_FILES_DATALAKE_DLLEXPORT const static PathSetAccessControlListRecursiveMode Set;
        AZ_STORAGE_FILES_DATALAKE_DLLEXPORT const static PathSetAccessControlListRecursiveMode
            Modify;
        AZ_STORAGE_FILES_DATALAKE_DLLEXPORT const static PathSetAccessControlListRecursiveMode
            Remove;

      private:
        std::string m_value;
      };
    } // namespace _detail
    class PublicAccessType final {
    public:
      PublicAccessType() = default;
      explicit PublicAccessType(std::string value) : m_value(std::move(value)) {}
      bool operator==(const PublicAccessType& other) const { return m_value == other.m_value; }
      bool operator!=(const PublicAccessType& other) const { return !(*this == other); }
      const std::string& ToString() const { return m_value; }
      AZ_STORAGE_FILES_DATALAKE_DLLEXPORT const static PublicAccessType None;
      AZ_STORAGE_FILES_DATALAKE_DLLEXPORT const static PublicAccessType FileSystem;
      AZ_STORAGE_FILES_DATALAKE_DLLEXPORT const static PublicAccessType Path;

    private:
      std::string m_value;
    };
    namespace _detail {
      struct PathItem final
      {
        std::string Name;
        bool IsDirectory = false;
        DateTime LastModified;
        int64_t FileSize = int64_t();
        std::string Owner;
        std::string Group;
        std::string Permissions;
        /**
         * The name of the encryption scope under which the blob is encrypted.
         */
        Nullable<std::string> EncryptionScope;
        Nullable<std::string> CreatedOn;
        Nullable<std::string> ExpiresOn;
        Nullable<std::string> EncryptionContext;
        std::string ETag;
      };
      /**
       * @brief Response type for #Azure::Storage::Files::DataLake::FileSystemClient::ListPaths.
       */
      struct PathList final
      {
        /**
         * Array of PathItem.
         */
        std::vector<PathItem> Paths;
        /**
         * If the number of paths to be listed exceeds the maxResults limit, a continuation token is
         * returned in this response header.  When a continuation token is returned in the response,
         * it must be specified in a subsequent invocation of the list operation to continue listing
         * the paths.
         */
        Nullable<std::string> ContinuationToken;
      };
    } // namespace _detail
    /**
     * @brief Required only for Create File and Create Directory. The value must be "file" or
     * "directory".
     */
    class PathResourceType final {
    public:
      PathResourceType() = default;
      explicit PathResourceType(std::string value) : m_value(std::move(value)) {}
      bool operator==(const PathResourceType& other) const { return m_value == other.m_value; }
      bool operator!=(const PathResourceType& other) const { return !(*this == other); }
      const std::string& ToString() const { return m_value; }
      AZ_STORAGE_FILES_DATALAKE_DLLEXPORT const static PathResourceType Directory;
      AZ_STORAGE_FILES_DATALAKE_DLLEXPORT const static PathResourceType File;

    private:
      std::string m_value;
    };
    /**
     * @brief Response type for #Azure::Storage::Files::DataLake::PathClient::Create.
     */
    struct CreatePathResult final
    {
      /**
       * Indicates if the file or directory was successfully created by this operation.
       */
      bool Created = true;
      /**
       * An HTTP entity tag associated with the file or directory.
       */
      Azure::ETag ETag;
      /**
       * The data and time the file or directory was last modified.  Write operations on the file or
       * directory update the last modified time.
       */
      DateTime LastModified;
      /**
       * The size of the resource in bytes.
       */
      Nullable<int64_t> FileSize;
      /**
       * The value of this header is set to true if the contents of the request are successfully
       * encrypted using the specified algorithm, and false otherwise.
       */
      bool IsServerEncrypted = bool();
      /**
       * The SHA-256 hash of the encryption key used to encrypt the blob. This header is only
       * returned when the blob was encrypted with a customer-provided key.
       */
      Nullable<std::vector<uint8_t>> EncryptionKeySha256;
    };
    /**
     * @brief Response type for #Azure::Storage::Files::DataLake::PathClient::Delete.
     */
    struct DeletePathResult final
    {
      /**
       * Indicates if the file or directory was successfully deleted by this operation.
       */
      bool Deleted = true;
    };
    /**
     * @brief Response type for #Azure::Storage::Files::DataLake::PathClient::SetAccessControlList.
     */
    struct SetPathAccessControlListResult final
    {
      /**
       * An HTTP entity tag associated with the file or directory.
       */
      Azure::ETag ETag;
      /**
       * The data and time the file or directory was last modified. Write operations on the file or
       * directory update the last modified time.
       */
      DateTime LastModified;
    };
    /**
     * @brief The failed entry when setting the Acl.
     */
    struct AclFailedEntry final
    {
      /**
       * Name of the failed entry.
       */
      std::string Name;
      /**
       * Type of the entry.
       */
      std::string Type;
      /**
       * Error message for the failure.
       */
      std::string ErrorMessage;
    };
    namespace _detail {
      /**
       * @brief Response type for
       * #Azure::Storage::Files::DataLake::PathClient::SetAccessControlListRecursive.
       */
      struct SetAccessControlListRecursiveResult final
      {
        int32_t NumberOfSuccessfulDirectories = int32_t();
        int32_t NumberOfSuccessfulFiles = int32_t();
        int32_t NumberOfFailures = int32_t();
        /**
         * Array of AclFailedEntry.
         */
        std::vector<AclFailedEntry> FailedEntries;
        /**
         * When performing setAccessControlRecursive on a directory, the number of paths that are
         * processed with each invocation is limited.  If the number of paths to be processed
         * exceeds this limit, a continuation token is returned in this response header.  When a
         * continuation token is returned in the response, it must be specified in a subsequent
         * invocation of the setAccessControlRecursive operation to continue the
         * setAccessControlRecursive operation on the directory.
         */
        Nullable<std::string> ContinuationToken;
      };
      /**
       * @brief Response type for #Azure::Storage::Files::DataLake::PathClient::Undelete.
       */
      struct UndeletePathResult final
      {
        /**
         * The type of the resource.  The value may be "file" or "directory".  If not set, the value
         * is "file".
         */
        Nullable<std::string> ResourceType;
      };
      /**
       * @brief Response type for
       * #Azure::Storage::Files::DataLake::PathClient::GetAccessControlList.
       */
      struct GetPathAccessControlListResult final
      {
        /**
         * The owner of the file or directory. Included in the response if Hierarchical Namespace is
         * enabled for the account.
         */
        std::string Owner;
        /**
         * The owning group of the file or directory. Included in the response if Hierarchical
         * Namespace is enabled for the account.
         */
        std::string Group;
        /**
         * The POSIX access permissions for the file owner, the file owning group, and others.
         * Included in the response if Hierarchical Namespace is enabled for the account.
         */
        std::string Permissions;
        /**
         * The POSIX access control list for the file or directory.  Included in the response only
         * if the action is "getAccessControl" and Hierarchical Namespace is enabled for the
         * account.
         */
        std::string Acl;
      };
    } // namespace _detail
    /**
     * @brief Optional. If "acquire" it will acquire the lease. If "auto-renew" it will renew the
     * lease. If "release" it will release the lease only on flush. If "acquire-release" it will
     * acquire & complete the operation & release the lease once operation is done.
     */
    class LeaseAction final {
    public:
      LeaseAction() = default;
      explicit LeaseAction(std::string value) : m_value(std::move(value)) {}
      bool operator==(const LeaseAction& other) const { return m_value == other.m_value; }
      bool operator!=(const LeaseAction& other) const { return !(*this == other); }
      const std::string& ToString() const { return m_value; }
      AZ_STORAGE_FILES_DATALAKE_DLLEXPORT const static LeaseAction Acquire;
      AZ_STORAGE_FILES_DATALAKE_DLLEXPORT const static LeaseAction AutoRenew;
      AZ_STORAGE_FILES_DATALAKE_DLLEXPORT const static LeaseAction Release;
      AZ_STORAGE_FILES_DATALAKE_DLLEXPORT const static LeaseAction AcquireRelease;

    private:
      std::string m_value;
    };
    /**
     * @brief Response type for #Azure::Storage::Files::DataLake::FileClient::Flush.
     */
    struct FlushFileResult final
    {
      /**
       * An HTTP entity tag associated with the file or directory.
       */
      Azure::ETag ETag;
      /**
       * The data and time the file or directory was last modified.  Write operations on the file or
       * directory update the last modified time.
       */
      DateTime LastModified;
      /**
       * The size of the resource in bytes.
       */
      int64_t FileSize = int64_t();
      /**
       * The value of this header is set to true if the contents of the request are successfully
       * encrypted using the specified algorithm, and false otherwise.
       */
      bool IsServerEncrypted = bool();
      /**
       * The SHA-256 hash of the encryption key used to encrypt the blob. This header is only
       * returned when the blob was encrypted with a customer-provided key.
       */
      Nullable<std::vector<uint8_t>> EncryptionKeySha256;
      /**
       * If the lease was auto-renewed with this request.
       */
      Nullable<bool> IsLeaseRenewed;
    };
    /**
     * @brief Response type for #Azure::Storage::Files::DataLake::FileClient::Append.
     */
    struct AppendFileResult final
    {
      /**
       * If the blob has an MD5 hash and this operation is to read the full blob, this response
       * header is returned so that the client can check for message content integrity.
       */
      Nullable<ContentHash> TransactionalContentHash;
      /**
       * The value of this header is set to true if the contents of the request are successfully
       * encrypted using the specified algorithm, and false otherwise.
       */
      bool IsServerEncrypted = bool();
      /**
       * The SHA-256 hash of the encryption key used to encrypt the blob. This header is only
       * returned when the blob was encrypted with a customer-provided key.
       */
      Nullable<std::vector<uint8_t>> EncryptionKeySha256;
      /**
       * If the lease was auto-renewed with this request.
       */
      Nullable<bool> IsLeaseRenewed;
    };
  } // namespace Models
  namespace _detail {
    class FileSystemClient final {
    public:
      struct ListFileSystemPathsOptions final
      {
        Nullable<std::string> RequestId;
        Nullable<int32_t> Timeout;
        Nullable<std::string> ContinuationToken;
        Nullable<std::string> Path;
        bool Recursive = bool();
        Nullable<int32_t> MaxResults;
        Nullable<bool> Upn;
      };
      static Response<Models::_detail::PathList> ListPaths(
          Core::Http::_internal::HttpPipeline& pipeline,
          const Core::Url& url,
          const ListFileSystemPathsOptions& options,
          const Core::Context& context);
    };
    class PathClient final {
    public:
      struct CreatePathOptions final
      {
        Nullable<std::string> RequestId;
        Nullable<int32_t> Timeout;
        Nullable<Models::PathResourceType> Resource;
        Nullable<std::string> ContinuationToken;
        Nullable<std::string> Mode;
        Nullable<std::string> CacheControl;
        Nullable<std::string> ContentEncoding;
        Nullable<std::string> ContentLanguage;
        Nullable<std::string> ContentDisposition;
        Nullable<std::string> ContentType;
        Nullable<std::string> RenameSource;
        Nullable<std::string> LeaseId;
        Nullable<std::string> SourceLeaseId;
        Nullable<std::string> Properties;
        Nullable<std::string> Permissions;
        Nullable<std::string> Umask;
        ETag IfMatch;
        ETag IfNoneMatch;
        Nullable<DateTime> IfModifiedSince;
        Nullable<DateTime> IfUnmodifiedSince;
        ETag SourceIfMatch;
        ETag SourceIfNoneMatch;
        Nullable<DateTime> SourceIfModifiedSince;
        Nullable<DateTime> SourceIfUnmodifiedSince;
        Nullable<std::string> EncryptionKey;
        Nullable<std::vector<uint8_t>> EncryptionKeySha256;
        Nullable<std::string> EncryptionAlgorithm;
        Nullable<std::string> Owner;
        Nullable<std::string> Group;
        Nullable<std::string> Acl;
        Nullable<std::string> ProposedLeaseId;
        Nullable<int64_t> LeaseDuration;
        Nullable<std::string> ExpiryOptions;
        Nullable<std::string> ExpiresOn;
        Nullable<std::string> EncryptionContext;
      };
      static Response<Models::CreatePathResult> Create(
          Core::Http::_internal::HttpPipeline& pipeline,
          const Core::Url& url,
          const CreatePathOptions& options,
          const Core::Context& context);
      struct DeletePathOptions final
      {
        Nullable<std::string> RequestId;
        Nullable<int32_t> Timeout;
        Nullable<bool> Recursive;
        Nullable<std::string> ContinuationToken;
        Nullable<std::string> LeaseId;
        ETag IfMatch;
        ETag IfNoneMatch;
        Nullable<DateTime> IfModifiedSince;
        Nullable<DateTime> IfUnmodifiedSince;
      };
      static Response<Models::DeletePathResult> Delete(
          Core::Http::_internal::HttpPipeline& pipeline,
          const Core::Url& url,
          const DeletePathOptions& options,
          const Core::Context& context);
      struct SetPathAccessControlListOptions final
      {
        Nullable<std::string> LeaseId;
        Nullable<std::string> Owner;
        Nullable<std::string> Group;
        Nullable<std::string> Permissions;
        Nullable<std::string> Acl;
        ETag IfMatch;
        ETag IfNoneMatch;
        Nullable<DateTime> IfModifiedSince;
        Nullable<DateTime> IfUnmodifiedSince;
      };
      static Response<Models::SetPathAccessControlListResult> SetAccessControlList(
          Core::Http::_internal::HttpPipeline& pipeline,
          const Core::Url& url,
          const SetPathAccessControlListOptions& options,
          const Core::Context& context);
      struct SetPathAccessControlListRecursiveOptions final
      {
        Nullable<std::string> ContinuationToken;
        std::string Mode;
        Nullable<bool> ForceFlag;
        Nullable<int32_t> MaxRecords;
        Nullable<std::string> Acl;
      };
      static Response<Models::_detail::SetAccessControlListRecursiveResult>
      SetAccessControlListRecursive(
          Core::Http::_internal::HttpPipeline& pipeline,
          const Core::Url& url,
          const SetPathAccessControlListRecursiveOptions& options,
          const Core::Context& context);
      struct UndeletePathOptions final
      {
        Nullable<std::string> UndeleteSource;
      };
      static Response<Models::_detail::UndeletePathResult> Undelete(
          Core::Http::_internal::HttpPipeline& pipeline,
          const Core::Url& url,
          const UndeletePathOptions& options,
          const Core::Context& context);
      struct GetPathAccessControlListOptions final
      {
        Nullable<bool> Upn;
        Nullable<std::string> LeaseId;
        ETag IfMatch;
        ETag IfNoneMatch;
        Nullable<DateTime> IfModifiedSince;
        Nullable<DateTime> IfUnmodifiedSince;
      };
      static Response<Models::_detail::GetPathAccessControlListResult> GetAccessControlList(
          Core::Http::_internal::HttpPipeline& pipeline,
          const Core::Url& url,
          const GetPathAccessControlListOptions& options,
          const Core::Context& context);
    };
    class FileClient final {
    public:
      struct FlushFileOptions final
      {
        Nullable<int64_t> Position;
        Nullable<bool> RetainUncommittedData;
        Nullable<bool> Close;
        Nullable<std::vector<uint8_t>> ContentMD5;
        Nullable<std::string> LeaseId;
        Nullable<Models::LeaseAction> LeaseAction;
        Nullable<int64_t> LeaseDuration;
        Nullable<std::string> ProposedLeaseId;
        Nullable<std::string> CacheControl;
        Nullable<std::string> ContentType;
        Nullable<std::string> ContentDisposition;
        Nullable<std::string> ContentEncoding;
        Nullable<std::string> ContentLanguage;
        ETag IfMatch;
        ETag IfNoneMatch;
        Nullable<DateTime> IfModifiedSince;
        Nullable<DateTime> IfUnmodifiedSince;
        Nullable<std::string> EncryptionKey;
        Nullable<std::vector<uint8_t>> EncryptionKeySha256;
        Nullable<std::string> EncryptionAlgorithm;
      };
      static Response<Models::FlushFileResult> Flush(
          Core::Http::_internal::HttpPipeline& pipeline,
          const Core::Url& url,
          const FlushFileOptions& options,
          const Core::Context& context);
      struct AppendFileOptions final
      {
        Nullable<int64_t> Position;
        Nullable<std::vector<uint8_t>> TransactionalContentHash;
        Nullable<std::vector<uint8_t>> TransactionalContentCrc64;
        Nullable<std::string> LeaseId;
        Nullable<Models::LeaseAction> LeaseAction;
        Nullable<int64_t> LeaseDuration;
        Nullable<std::string> ProposedLeaseId;
        Nullable<std::string> EncryptionKey;
        Nullable<std::vector<uint8_t>> EncryptionKeySha256;
        Nullable<std::string> EncryptionAlgorithm;
        Nullable<bool> Flush;
      };
      static Response<Models::AppendFileResult> Append(
          Core::Http::_internal::HttpPipeline& pipeline,
          const Core::Url& url,
          Core::IO::BodyStream& requestBody,
          const AppendFileOptions& options,
          const Core::Context& context);
    };
  } // namespace _detail
}}}} // namespace Azure::Storage::Files::DataLake