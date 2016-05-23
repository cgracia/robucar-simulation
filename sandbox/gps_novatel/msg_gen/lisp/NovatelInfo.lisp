; Auto-generated. Do not edit!


(cl:in-package gps_novatel-msg)


;//! \htmlinclude NovatelInfo.msg.html

(cl:defclass <NovatelInfo> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (sol_status
    :reader sol_status
    :initarg :sol_status
    :type cl:fixnum
    :initform 0)
   (pos_type
    :reader pos_type
    :initarg :pos_type
    :type cl:fixnum
    :initform 0)
   (lat
    :reader lat
    :initarg :lat
    :type cl:float
    :initform 0.0)
   (lon
    :reader lon
    :initarg :lon
    :type cl:float
    :initform 0.0)
   (alt
    :reader alt
    :initarg :alt
    :type cl:float
    :initform 0.0)
   (ondulation
    :reader ondulation
    :initarg :ondulation
    :type cl:float
    :initform 0.0)
   (datum_id
    :reader datum_id
    :initarg :datum_id
    :type cl:fixnum
    :initform 0)
   (sigmaLat
    :reader sigmaLat
    :initarg :sigmaLat
    :type cl:float
    :initform 0.0)
   (sigmaLon
    :reader sigmaLon
    :initarg :sigmaLon
    :type cl:float
    :initform 0.0)
   (sigmaAlt
    :reader sigmaAlt
    :initarg :sigmaAlt
    :type cl:float
    :initform 0.0)
   (base_id
    :reader base_id
    :initarg :base_id
    :type cl:string
    :initform "")
   (diff_age
    :reader diff_age
    :initarg :diff_age
    :type cl:float
    :initform 0.0)
   (sol_age
    :reader sol_age
    :initarg :sol_age
    :type cl:float
    :initform 0.0)
   (nObs
    :reader nObs
    :initarg :nObs
    :type cl:fixnum
    :initform 0)
   (nGPSL
    :reader nGPSL
    :initarg :nGPSL
    :type cl:fixnum
    :initform 0)
   (nL1
    :reader nL1
    :initarg :nL1
    :type cl:fixnum
    :initform 0)
   (nL2
    :reader nL2
    :initarg :nL2
    :type cl:fixnum
    :initform 0))
)

(cl:defclass NovatelInfo (<NovatelInfo>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <NovatelInfo>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'NovatelInfo)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name gps_novatel-msg:<NovatelInfo> is deprecated: use gps_novatel-msg:NovatelInfo instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <NovatelInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gps_novatel-msg:header-val is deprecated.  Use gps_novatel-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'sol_status-val :lambda-list '(m))
(cl:defmethod sol_status-val ((m <NovatelInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gps_novatel-msg:sol_status-val is deprecated.  Use gps_novatel-msg:sol_status instead.")
  (sol_status m))

(cl:ensure-generic-function 'pos_type-val :lambda-list '(m))
(cl:defmethod pos_type-val ((m <NovatelInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gps_novatel-msg:pos_type-val is deprecated.  Use gps_novatel-msg:pos_type instead.")
  (pos_type m))

(cl:ensure-generic-function 'lat-val :lambda-list '(m))
(cl:defmethod lat-val ((m <NovatelInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gps_novatel-msg:lat-val is deprecated.  Use gps_novatel-msg:lat instead.")
  (lat m))

(cl:ensure-generic-function 'lon-val :lambda-list '(m))
(cl:defmethod lon-val ((m <NovatelInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gps_novatel-msg:lon-val is deprecated.  Use gps_novatel-msg:lon instead.")
  (lon m))

(cl:ensure-generic-function 'alt-val :lambda-list '(m))
(cl:defmethod alt-val ((m <NovatelInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gps_novatel-msg:alt-val is deprecated.  Use gps_novatel-msg:alt instead.")
  (alt m))

(cl:ensure-generic-function 'ondulation-val :lambda-list '(m))
(cl:defmethod ondulation-val ((m <NovatelInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gps_novatel-msg:ondulation-val is deprecated.  Use gps_novatel-msg:ondulation instead.")
  (ondulation m))

(cl:ensure-generic-function 'datum_id-val :lambda-list '(m))
(cl:defmethod datum_id-val ((m <NovatelInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gps_novatel-msg:datum_id-val is deprecated.  Use gps_novatel-msg:datum_id instead.")
  (datum_id m))

(cl:ensure-generic-function 'sigmaLat-val :lambda-list '(m))
(cl:defmethod sigmaLat-val ((m <NovatelInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gps_novatel-msg:sigmaLat-val is deprecated.  Use gps_novatel-msg:sigmaLat instead.")
  (sigmaLat m))

(cl:ensure-generic-function 'sigmaLon-val :lambda-list '(m))
(cl:defmethod sigmaLon-val ((m <NovatelInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gps_novatel-msg:sigmaLon-val is deprecated.  Use gps_novatel-msg:sigmaLon instead.")
  (sigmaLon m))

(cl:ensure-generic-function 'sigmaAlt-val :lambda-list '(m))
(cl:defmethod sigmaAlt-val ((m <NovatelInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gps_novatel-msg:sigmaAlt-val is deprecated.  Use gps_novatel-msg:sigmaAlt instead.")
  (sigmaAlt m))

(cl:ensure-generic-function 'base_id-val :lambda-list '(m))
(cl:defmethod base_id-val ((m <NovatelInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gps_novatel-msg:base_id-val is deprecated.  Use gps_novatel-msg:base_id instead.")
  (base_id m))

(cl:ensure-generic-function 'diff_age-val :lambda-list '(m))
(cl:defmethod diff_age-val ((m <NovatelInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gps_novatel-msg:diff_age-val is deprecated.  Use gps_novatel-msg:diff_age instead.")
  (diff_age m))

(cl:ensure-generic-function 'sol_age-val :lambda-list '(m))
(cl:defmethod sol_age-val ((m <NovatelInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gps_novatel-msg:sol_age-val is deprecated.  Use gps_novatel-msg:sol_age instead.")
  (sol_age m))

(cl:ensure-generic-function 'nObs-val :lambda-list '(m))
(cl:defmethod nObs-val ((m <NovatelInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gps_novatel-msg:nObs-val is deprecated.  Use gps_novatel-msg:nObs instead.")
  (nObs m))

(cl:ensure-generic-function 'nGPSL-val :lambda-list '(m))
(cl:defmethod nGPSL-val ((m <NovatelInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gps_novatel-msg:nGPSL-val is deprecated.  Use gps_novatel-msg:nGPSL instead.")
  (nGPSL m))

(cl:ensure-generic-function 'nL1-val :lambda-list '(m))
(cl:defmethod nL1-val ((m <NovatelInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gps_novatel-msg:nL1-val is deprecated.  Use gps_novatel-msg:nL1 instead.")
  (nL1 m))

(cl:ensure-generic-function 'nL2-val :lambda-list '(m))
(cl:defmethod nL2-val ((m <NovatelInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader gps_novatel-msg:nL2-val is deprecated.  Use gps_novatel-msg:nL2 instead.")
  (nL2 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <NovatelInfo>) ostream)
  "Serializes a message object of type '<NovatelInfo>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'sol_status)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'sol_status)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'pos_type)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'pos_type)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'lat))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'lon))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'alt))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ondulation))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'datum_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'datum_id)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'sigmaLat))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'sigmaLon))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'sigmaAlt))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'base_id))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'base_id))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'diff_age))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'sol_age))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'nObs)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'nObs)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'nGPSL)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'nGPSL)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'nL1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'nL1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'nL2)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'nL2)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <NovatelInfo>) istream)
  "Deserializes a message object of type '<NovatelInfo>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'sol_status)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'sol_status)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'pos_type)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'pos_type)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'lat) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'lon) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'alt) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ondulation) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'datum_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'datum_id)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'sigmaLat) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'sigmaLon) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'sigmaAlt) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'base_id) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'base_id) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'diff_age) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'sol_age) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'nObs)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'nObs)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'nGPSL)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'nGPSL)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'nL1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'nL1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'nL2)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'nL2)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<NovatelInfo>)))
  "Returns string type for a message object of type '<NovatelInfo>"
  "gps_novatel/NovatelInfo")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NovatelInfo)))
  "Returns string type for a message object of type 'NovatelInfo"
  "gps_novatel/NovatelInfo")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<NovatelInfo>)))
  "Returns md5sum for a message object of type '<NovatelInfo>"
  "fffc7fc92588667ebe9605af5853709c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'NovatelInfo)))
  "Returns md5sum for a message object of type 'NovatelInfo"
  "fffc7fc92588667ebe9605af5853709c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<NovatelInfo>)))
  "Returns full string definition for message of type '<NovatelInfo>"
  (cl:format cl:nil "Header header~%uint16 sol_status~%uint16 pos_type~%float64 lat~%float64 lon~%float64 alt~%float64 ondulation~%uint16 datum_id ~%float64 sigmaLat~%float64 sigmaLon~%float64 sigmaAlt~%string base_id~%float64 diff_age~%float64 sol_age~%uint16 nObs~%uint16 nGPSL~%uint16 nL1~%uint16 nL2~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'NovatelInfo)))
  "Returns full string definition for message of type 'NovatelInfo"
  (cl:format cl:nil "Header header~%uint16 sol_status~%uint16 pos_type~%float64 lat~%float64 lon~%float64 alt~%float64 ondulation~%uint16 datum_id ~%float64 sigmaLat~%float64 sigmaLon~%float64 sigmaAlt~%string base_id~%float64 diff_age~%float64 sol_age~%uint16 nObs~%uint16 nGPSL~%uint16 nL1~%uint16 nL2~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <NovatelInfo>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     2
     2
     8
     8
     8
     8
     2
     8
     8
     8
     4 (cl:length (cl:slot-value msg 'base_id))
     8
     8
     2
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <NovatelInfo>))
  "Converts a ROS message object to a list"
  (cl:list 'NovatelInfo
    (cl:cons ':header (header msg))
    (cl:cons ':sol_status (sol_status msg))
    (cl:cons ':pos_type (pos_type msg))
    (cl:cons ':lat (lat msg))
    (cl:cons ':lon (lon msg))
    (cl:cons ':alt (alt msg))
    (cl:cons ':ondulation (ondulation msg))
    (cl:cons ':datum_id (datum_id msg))
    (cl:cons ':sigmaLat (sigmaLat msg))
    (cl:cons ':sigmaLon (sigmaLon msg))
    (cl:cons ':sigmaAlt (sigmaAlt msg))
    (cl:cons ':base_id (base_id msg))
    (cl:cons ':diff_age (diff_age msg))
    (cl:cons ':sol_age (sol_age msg))
    (cl:cons ':nObs (nObs msg))
    (cl:cons ':nGPSL (nGPSL msg))
    (cl:cons ':nL1 (nL1 msg))
    (cl:cons ':nL2 (nL2 msg))
))
