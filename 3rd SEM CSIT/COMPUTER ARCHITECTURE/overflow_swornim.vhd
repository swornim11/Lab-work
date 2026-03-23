library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity overflow_swornim is
port(
a: in std_logic_vector(3 downto 0);
b: in std_logic_vector(3 downto 0);
overflow: out STD_LOGIC
);
end entity overflow_swornim;
architecture Behavioral of overflow_swornim is
begin
process(a,b)
variable sum: std_logic_vector (4 downto 0);
begin 
sum := ('0' & a) + ('0' & b);
if sum(sum'high)='1'
then overflow <= '1';
else 
overflow <= '0';
end if;
end process;
end architecture Behavioral;

