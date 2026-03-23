
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity ALU_swornim is
    Port (
        A, B   : in  STD_LOGIC_VECTOR(3 downto 0);
        sel    : in  STD_LOGIC_VECTOR(2 downto 0);
        Result : out STD_LOGIC_VECTOR(3 downto 0)
    );
end ALU_swornim;

architecture Behavioral of ALU_swornim is
begin
    process(A, B, sel)
    begin
        case sel is

            when "000" => -- ADD
                Result <= A + B;

            when "001" => -- SUB
                Result <= A - B;

            when "010" => -- AND
                Result <= A and B;

            when "011" => -- OR
                Result <= A or B;

            when "100" => -- NOT A
                Result <= not A;

            when "101" => -- XOR
                Result <= A xor B;

            when "110" => -- Increment A
                Result <= A + 1;

            when "111" => -- Clear
                Result <= "0000";

            when others =>
                Result <= "0000";

        end case;
    end process;

end Behavioral;