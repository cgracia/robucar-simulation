
(cl:in-package :asdf)

(defsystem "rosbucar-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "CarLikeInfo" :depends-on ("_package_CarLikeInfo"))
    (:file "_package_CarLikeInfo" :depends-on ("_package"))
    (:file "DriveCmd" :depends-on ("_package_DriveCmd"))
    (:file "_package_DriveCmd" :depends-on ("_package"))
    (:file "CarLikeCmd" :depends-on ("_package_CarLikeCmd"))
    (:file "_package_CarLikeCmd" :depends-on ("_package"))
    (:file "DriveInfo" :depends-on ("_package_DriveInfo"))
    (:file "_package_DriveInfo" :depends-on ("_package"))
  ))