; Auto-generated. Do not edit!


(cl:in-package rosbucar-msg)


;//! \htmlinclude CarLikeCmd.msg.html

(cl:defclass <CarLikeCmd> (roslisp-msg-protocol:ros-message)
  ((action
    :reader action
    :initarg :action
    :type cl:fixnum
    :initform 0)
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

(cl:defclass CarLikeCmd (<CarLikeCmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CarLikeCmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CarLikeCmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rosbucar-msg:<CarLikeCmd> is deprecated: use rosbucar-msg:CarLikeCmd instead.")))

(cl:ensure-generic-function 'action-val :lambda-list '(m))
(cl:defmethod action-val ((m <CarLikeCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbucar-msg:action-val is deprecated.  Use rosbucar-msg:action instead.")
  (action m))

(cl:ensure-generic-function 'target_speed-val :lambda-list '(m))
(cl:defmethod target_speed-val ((m <CarLikeCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbucar-msg:target_speed-val is deprecated.  Use rosbucar-msg:target_speed instead.")
  (target_speed m))

(cl:ensure-generic-function 'target_steering-val :lambda-list '(m))
(cl:defmethod target_steering-val ((m <CarLikeCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rosbucar-msg:target_steering-val is deprecated.  Use rosbucar-msg:target_steering instead.")
  (target_steering m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CarLikeCmd>) ostream)
  "Serializes a message object of type '<CarLikeCmd>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'action)) ostream)
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CarLikeCmd>) istream)
  "Deserializes a message object of type '<CarLikeCmd>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'action)) (cl:read-byte istream))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CarLikeCmd>)))
  "Returns string type for a message object of type '<CarLikeCmd>"
  "rosbucar/CarLikeCmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CarLikeCmd)))
  "Returns string type for a message object of type 'CarLikeCmd"
  "rosbucar/CarLikeCmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CarLikeCmd>)))
  "Returns md5sum for a message object of type '<CarLikeCmd>"
  "273058188caa05af1326783afad3d2f9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CarLikeCmd)))
  "Returns md5sum for a message object of type 'CarLikeCmd"
  "273058188caa05af1326783afad3d2f9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CarLikeCmd>)))
  "Returns full string definition for message of type '<CarLikeCmd>"
  (cl:format cl:nil "uint8 action~%float32 target_speed~%float32 target_steering~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CarLikeCmd)))
  "Returns full string definition for message of type 'CarLikeCmd"
  (cl:format cl:nil "uint8 action~%float32 target_speed~%float32 target_steering~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CarLikeCmd>))
  (cl:+ 0
     1
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CarLikeCmd>))
  "Converts a ROS message object to a list"
  (cl:list 'CarLikeCmd
    (cl:cons ':action (action msg))
    (cl:cons ':target_speed (target_speed msg))
    (cl:cons ':target_steering (target_steering msg))
))
