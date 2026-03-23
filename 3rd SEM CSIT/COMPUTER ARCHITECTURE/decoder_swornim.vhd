
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity decoder_swornim is
    Port ( A : in STD_LOGIC_VECTOR (1 downto 0);
           Y : out STD_LOGIC_VECTOR (3 downto 0));
end decoder_swornim;

architecture Behavioral of decoder_swornim is
begin
    process(A)
    begin
        case A is
            when "00" => Y <= "0001";
            when "01" => Y <= "0010";
            when "10" => Y <= "0100";
            when "11" => Y <= "1000";
            when others => Y <= "0000";
        end case;
    end process;
end Behavioral;