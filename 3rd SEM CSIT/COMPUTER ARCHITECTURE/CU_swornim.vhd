
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity CU_swornim is
    Port (
        opcode    : in  STD_LOGIC_VECTOR(2 downto 0);
        RegWrite  : out STD_LOGIC;
        MemRead   : out STD_LOGIC;
        MemWrite  : out STD_LOGIC;
        ALUOp     : out STD_LOGIC_VECTOR(1 downto 0)
    );
end CU_swornim;

architecture Behavioral of CU_swornim is
begin
    process(opcode)
    begin
        case opcode is

            -- ADD instruction
            when "000" =>
                RegWrite <= '1';
                MemRead  <= '0';
                MemWrite <= '0';
                ALUOp    <= "00";

            -- SUB instruction
            when "001" =>
                RegWrite <= '1';
                MemRead  <= '0';
                MemWrite <= '0';
                ALUOp    <= "01";

            -- LOAD instruction
            when "010" =>
                RegWrite <= '1';
                MemRead  <= '1';
                MemWrite <= '0';
                ALUOp    <= "10";

            -- STORE instruction
            when "011" =>
                RegWrite <= '0';
                MemRead  <= '0';
                MemWrite <= '1';
                ALUOp    <= "10";

            -- AND instruction
            when "100" =>
                RegWrite <= '1';
                MemRead  <= '0';
                MemWrite <= '0';
                ALUOp    <= "11";

            -- Default case
            when others =>
                RegWrite <= '0';
                MemRead  <= '0';
                MemWrite <= '0';
                ALUOp    <= "00";

        end case;
    end process;

end Behavioral;