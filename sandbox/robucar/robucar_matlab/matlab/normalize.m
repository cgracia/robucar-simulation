function output = normalize(angle)
% Returns the normalized value of the angle in radians.
% Angle is normalized between -pi and pi.

if (angle < -pi)
    while (angle < -pi)
        angle = angle + 2*pi;
    end
elseif (angle > pi)    
    while (angle > pi)
        angle = angle - 2*pi;
    end
end

output = angle;