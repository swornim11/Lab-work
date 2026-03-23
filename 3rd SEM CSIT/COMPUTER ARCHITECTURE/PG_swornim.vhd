library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity PG_swornim is 
   Port(
        A: in std_logic_vector(3 downto 0);
	p: out std_logic
  );
end PG_swornim;
architecture behavioral of PG_swornim is
begin

   p<= A(0) XOR A(1) XOR A(2) XOR A(3);
end behavioral;
