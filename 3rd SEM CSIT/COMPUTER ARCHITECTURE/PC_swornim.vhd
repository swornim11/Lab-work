library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity PC_swornim is
    Port ( A : in STD_LOGIC_VECTOR (3 downto 0);
           P : in STD_LOGIC;
           Error : out STD_LOGIC);
end PC_swornim;

architecture Behavioral of PC_swornim is
begin
    Error <= A(0) XOR A(1) XOR A(2) XOR A(3) XOR P;
end Behavioral;
