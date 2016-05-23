"""autogenerated by genmsg_py from speed_requestRequest.msg. Do not edit."""
import roslib.message
import struct


class speed_requestRequest(roslib.message.Message):
  _md5sum = "90af05bb5ec0723fcb08c5d09a8c0b69"
  _type = "robucar_simulation/speed_requestRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """float64 linear_speed_required
float64 angular_speed_required

"""
  __slots__ = ['linear_speed_required','angular_speed_required']
  _slot_types = ['float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.
    
    The available fields are:
       linear_speed_required,angular_speed_required
    
    @param args: complete set of field values, in .msg order
    @param kwds: use keyword arguments corresponding to message field names
    to set specific fields. 
    """
    if args or kwds:
      super(speed_requestRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.linear_speed_required is None:
        self.linear_speed_required = 0.
      if self.angular_speed_required is None:
        self.angular_speed_required = 0.
    else:
      self.linear_speed_required = 0.
      self.angular_speed_required = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    @param buff: buffer
    @type  buff: StringIO
    """
    try:
      _x = self
      buff.write(_struct_2d.pack(_x.linear_speed_required, _x.angular_speed_required))
    except struct.error, se: self._check_types(se)
    except TypeError, te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    @param str: byte array of serialized message
    @type  str: str
    """
    try:
      end = 0
      _x = self
      start = end
      end += 16
      (_x.linear_speed_required, _x.angular_speed_required,) = _struct_2d.unpack(str[start:end])
      return self
    except struct.error, e:
      raise roslib.message.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    @param buff: buffer
    @type  buff: StringIO
    @param numpy: numpy python module
    @type  numpy module
    """
    try:
      _x = self
      buff.write(_struct_2d.pack(_x.linear_speed_required, _x.angular_speed_required))
    except struct.error, se: self._check_types(se)
    except TypeError, te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    @param str: byte array of serialized message
    @type  str: str
    @param numpy: numpy python module
    @type  numpy: module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 16
      (_x.linear_speed_required, _x.angular_speed_required,) = _struct_2d.unpack(str[start:end])
      return self
    except struct.error, e:
      raise roslib.message.DeserializationError(e) #most likely buffer underfill

_struct_I = roslib.message.struct_I
_struct_2d = struct.Struct("<2d")
"""autogenerated by genmsg_py from speed_requestResponse.msg. Do not edit."""
import roslib.message
import struct


class speed_requestResponse(roslib.message.Message):
  _md5sum = "66cf2b84c0682ad02b9fface02d68f5c"
  _type = "robucar_simulation/speed_requestResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """bool speed_set
float64 linear_speed_set
float64 angular_speed_set


"""
  __slots__ = ['speed_set','linear_speed_set','angular_speed_set']
  _slot_types = ['bool','float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.
    
    The available fields are:
       speed_set,linear_speed_set,angular_speed_set
    
    @param args: complete set of field values, in .msg order
    @param kwds: use keyword arguments corresponding to message field names
    to set specific fields. 
    """
    if args or kwds:
      super(speed_requestResponse, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.speed_set is None:
        self.speed_set = False
      if self.linear_speed_set is None:
        self.linear_speed_set = 0.
      if self.angular_speed_set is None:
        self.angular_speed_set = 0.
    else:
      self.speed_set = False
      self.linear_speed_set = 0.
      self.angular_speed_set = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    @param buff: buffer
    @type  buff: StringIO
    """
    try:
      _x = self
      buff.write(_struct_B2d.pack(_x.speed_set, _x.linear_speed_set, _x.angular_speed_set))
    except struct.error, se: self._check_types(se)
    except TypeError, te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    @param str: byte array of serialized message
    @type  str: str
    """
    try:
      end = 0
      _x = self
      start = end
      end += 17
      (_x.speed_set, _x.linear_speed_set, _x.angular_speed_set,) = _struct_B2d.unpack(str[start:end])
      self.speed_set = bool(self.speed_set)
      return self
    except struct.error, e:
      raise roslib.message.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    @param buff: buffer
    @type  buff: StringIO
    @param numpy: numpy python module
    @type  numpy module
    """
    try:
      _x = self
      buff.write(_struct_B2d.pack(_x.speed_set, _x.linear_speed_set, _x.angular_speed_set))
    except struct.error, se: self._check_types(se)
    except TypeError, te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    @param str: byte array of serialized message
    @type  str: str
    @param numpy: numpy python module
    @type  numpy: module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 17
      (_x.speed_set, _x.linear_speed_set, _x.angular_speed_set,) = _struct_B2d.unpack(str[start:end])
      self.speed_set = bool(self.speed_set)
      return self
    except struct.error, e:
      raise roslib.message.DeserializationError(e) #most likely buffer underfill

_struct_I = roslib.message.struct_I
_struct_B2d = struct.Struct("<B2d")
class speed_request(roslib.message.ServiceDefinition):
  _type          = 'robucar_simulation/speed_request'
  _md5sum = 'bbad68639eadea0991ba09527bfc9629'
  _request_class  = speed_requestRequest
  _response_class = speed_requestResponse
