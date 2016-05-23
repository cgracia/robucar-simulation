; Auto-generated. Do not edit!


(cl:in-package rosbucar-msg)


;//! \htmlinclude DriveCmd.msg.html

(cl:defclass <DriveCmd> (roslisp-msg-protocol:ros-message)
  ((control_mode
    :reader control_mode
    :initarg :control_mode
    :type cl:fixnum
    :initform 0)
   (enabled
    :reader enabled
    :initarg :enabled
    :type cl:fixnum
    :initform 0)
   (value
    :reader value
    :initarg :value
    :type cl:float
    :initform 0.0))
)

(cl:defclass DriveCmd (<DriveCmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DriveCmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DriveCmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosbucar-msg:<DriveCmd> is deprecated: use rosbucar-msg:DriveCmd instead.")))

(cl:ensure-generic-function 'control_mode-val :lambda-list '(m))
(cl:defmethod control_mode-val ((m <DriveCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbucar-msg:control_mode-val is deprecated.  Use rosbucar-msg:control_mode instead.")
  (control_mode m))

(cl:ensure-generic-function 'enabled-val :lambda-list '(m))
(cl:defmethod enabled-val ((m <DriveCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbucar-msg:enabled-val is deprecated.  Use rosbucar-msg:enabled instead.")
  (enabled m))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <DriveCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbucar-msg:value-val is deprecated.  Use rosbucar-msg:value instead.")
  (value m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DriveCmd>) ostream)
  "Serializes a message object of type '<DriveCmd>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'control_mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'enabled)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'value))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DriveCmd>) istream)
  "Deserializes a message object of type '<DriveCmd>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'control_mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'enabled)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'value) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DriveCmd>)))
  "Returns string type for a message object of type '<DriveCmd>"
  "rosbucar/DriveCmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DriveCmd)))
  "Returns string type for a message object of type 'DriveCmd"
  "rosbucar/DriveCmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DriveCmd>)))
  "Returns md5sum for a message object of type '<DriveCmd>"
  "455e606c94e97c214f241839453a7b5c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DriveCmd)))
  "Returns md5sum for a message object of type 'DriveCmd"
  "455e606c94e97c214f241839453a7b5c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DriveCmd>)))
  "Returns full string definition for message of type '<DriveCmd>"
  (cl:format cl:nil "uint8 control_mode~%uint8 enabled~%float32 value~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DriveCmd)))
  "Returns full string definition for message of type 'DriveCmd"
  (cl:format cl:nil "uint8 control_mode~%uint8 enabled~%float32 value~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DriveCmd>))
  (cl:+ 0
     1
     1
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DriveCmd>))
  "Converts a ROS message object to a list"
  (cl:list 'DriveCmd
    (cl:cons ':control_mode (control_mode msg))
    (cl:cons ':enabled (enabled msg))
    (cl:cons ':value (value msg))
))
