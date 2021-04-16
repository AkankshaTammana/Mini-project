# Mini-project

This project helps to check whether the considered voltage and current values are feasible or not to run the power through the transmission line. 
It also shows the voltage regulation, efficiency and various losses(including corona losses, I2R losses) of the transmission line.

For every transmission line there are some parameters. They are as follows:
  1. Resistance: It is hindrance to the flow of current through the transmission line and measured in ohms.
                 For the tranmission line, we consider resistance per kilometer.
                 Its vaule will be small like 0.15 ohm per kilometer, 0.18 ohm per kilometer.
                 Inorder to get total resistance of the line, resistance per kilometer should be multiplied with the length of the transmission lines.
                 
  2. Inductance: It is similar to resistance and measured in henrys(H) or milli-henrys(mH).
                 For the tranmission line, we consider Inductance per kilometer.
                 Its value is also small like 2 mH
                 
  3. Radius    : It is radius of the transmission line.
                 It's major effect will be on corona losses.
                 
Based on the parameters of the transmission line and voltage, current as input parameters; This project gives detailed analysis of the transmission, so that we can understand that the considered pramaetrs, voltage and current inputs are feasible are not.
