
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity demux_swornim is
    Port (
        D : in STD_LOGIC;
        S : in STD_LOGIC_VECTOR(1 downto 0);
        Y : out STD_LOGIC_VECTOR(3 downto 0)
    );
end demux_swornim;

architecture Behavioral of demux_swornim is
begin
    process(D, S)
    begin
        Y <= "0000";  -- default

        case S is
            when "00" => Y(0) <= D;
            when "01" => Y(1) <= D;
            when "10" => Y(2) <= D;
            when "11" => Y(3) <= D;
            when others => null;
        end case;
    end process;
end Behavioral;