; Auto-generated. Do not edit!


(cl:in-package rosbucar-msg)


;//! \htmlinclude CarLikeInfo.msg.html

(cl:defclass <CarLikeInfo> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (status
    :reader status
    :initarg :status
    :type cl:fixnum
    :initform 0)
   (current_speed
    :reader current_speed
    :initarg :current_speed
    :type cl:float
    :initform 0.0)
   (current_steering
    :reader current_steering
    :initarg :current_steering
    :type cl:float
    :initform 0.0)
   (target_speed
    :reader target_speed
    :initarg :target_speed
    :type cl:float
    :initform 0.0)
   (target_steering
    :reader target_steering
    :initarg :target_steering
    :type cl:float
    :initform 0.0))
)

(cl:defclass CarLikeInfo (<CarLikeInfo>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CarLikeInfo>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CarLikeInfo)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosbucar-msg:<CarLikeInfo> is deprecated: use rosbucar-msg:CarLikeInfo instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <CarLikeInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbucar-msg:header-val is deprecated.  Use rosbucar-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'status-val :lambda-list '(m))
(cl:defmethod status-val ((m <CarLikeInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbucar-msg:status-val is deprecated.  Use rosbucar-msg:status instead.")
  (status m))

(cl:ensure-generic-function 'current_speed-val :lambda-list '(m))
(cl:defmethod current_speed-val ((m <CarLikeInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbucar-msg:current_speed-val is deprecated.  Use rosbucar-msg:current_speed instead.")
  (current_speed m))

(cl:ensure-generic-function 'current_steering-val :lambda-list '(m))
(cl:defmethod current_steering-val ((m <CarLikeInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbucar-msg:current_steering-val is deprecated.  Use rosbucar-msg:current_steering instead.")
  (current_steering m))

(cl:ensure-generic-function 'target_speed-val :lambda-list '(m))
(cl:defmethod target_speed-val ((m <CarLikeInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbucar-msg:target_speed-val is deprecated.  Use rosbucar-msg:target_speed instead.")
  (target_speed m))

(cl:ensure-generic-function 'target_steering-val :lambda-list '(m))
(cl:defmethod target_steering-val ((m <CarLikeInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbucar-msg:target_steering-val is deprecated.  Use rosbucar-msg:target_steering instead.")
  (target_steering m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CarLikeInfo>) ostream)
  "Serializes a message object of type '<CarLikeInfo>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'status)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'current_speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'current_steering))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'target_speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'target_steering))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CarLikeInfo>) istream)
  "Deserializes a message object of type '<CarLikeInfo>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'status)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'current_speed) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'current_steering) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'target_speed) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'target_steering) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CarLikeInfo>)))
  "Returns string type for a message object of type '<CarLikeInfo>"
  "rosbucar/CarLikeInfo")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CarLikeInfo)))
  "Returns string type for a message object of type 'CarLikeInfo"
  "rosbucar/CarLikeInfo")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CarLikeInfo>)))
  "Returns md5sum for a message object of type '<CarLikeInfo>"
  "f4b94786e7837b141f54f295f70c7a3d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CarLikeInfo)))
  "Returns md5sum for a message object of type 'CarLikeInfo"
  "f4b94786e7837b141f54f295f70c7a3d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CarLikeInfo>)))
  "Returns full string definition for message of type '<CarLikeInfo>"
  (cl:format cl:nil "Header header~%uint8 status~%float32 current_speed~%float32 current_steering~%float32 target_speed~%float32 target_steering~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CarLikeInfo)))
  "Returns full string definition for message of type 'CarLikeInfo"
  (cl:format cl:nil "Header header~%uint8 status~%float32 current_speed~%float32 current_steering~%float32 target_speed~%float32 target_steering~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CarLikeInfo>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CarLikeInfo>))
  "Converts a ROS message object to a list"
  (cl:list 'CarLikeInfo
    (cl:cons ':header (header msg))
    (cl:cons ':status (status msg))
    (cl:cons ':current_speed (current_speed msg))
    (cl:cons ':current_steering (current_steering msg))
    (cl:cons ':target_speed (target_speed msg))
    (cl:cons ':target_steering (target_steering msg))
))
