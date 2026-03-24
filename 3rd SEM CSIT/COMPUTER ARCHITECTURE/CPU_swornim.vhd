library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;  -- for arithmetic

entity CPU_swornim is
    Port (
        clk    : in  STD_LOGIC;
        reset  : in  STD_LOGIC;
        A, B   : in  STD_LOGIC_VECTOR(3 downto 0);
        result : out STD_LOGIC_VECTOR(3 downto 0)
    );
end CPU_swornim;

architecture Behavioral of CPU_swornim is
    signal state     : STD_LOGIC_VECTOR(1 downto 0);  -- operation selector
    signal alu_out   : STD_LOGIC_VECTOR(3 downto 0);  -- ALU output
begin

    -- Simple Control Unit (cycles through operations)
    process(clk, reset)
    begin
        if reset = '1' then
            state <= "00";  -- start with addition
        elsif rising_edge(clk) then
            -- cycle state 00->01->10->11->00->...
            case state is
                when "00" => state <= "01";  -- subtraction next
                when "01" => state <= "10";  -- AND next
                when "10" => state <= "11";  -- OR next
                when "11" => state <= "00";  -- addition next
                when others => state <= "00";
            end case;
        end if;
    end process;

    -- ALU process (combinational)
    process(A, B, state)
        variable tempA, tempB, tempResult : unsigned(3 downto 0);
    begin
        tempA := unsigned(A);
        tempB := unsigned(B);
        case state is
            when "00" => tempResult := tempA + tempB;   -- addition
            when "01" => tempResult := tempA - tempB;   -- subtraction
            when "10" => tempResult := tempA AND tempB; -- AND
            when "11" => tempResult := tempA OR tempB;  -- OR
            when others => tempResult := (others => '0');
        end case;
        alu_out <= std_logic_vector(tempResult);
    end process;

    -- Output
    result <= alu_out;

end Behavioral;
