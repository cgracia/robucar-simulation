
(cl:in-package :asdf)

(defsystem "gps_novatel-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "NovatelInfo" :depends-on ("_package_NovatelInfo"))
    (:file "_package_NovatelInfo" :depends-on ("_package"))
  ))