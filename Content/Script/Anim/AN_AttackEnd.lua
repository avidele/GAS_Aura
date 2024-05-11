--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

---@type AN_AttackEnd_C
local M = UnLua.Class()

function M:Received_Notify(MeshComp, Animation)
    local OwnerActor = MeshComp:GetOwner()
    local CombatComponent = OwnerActor:GetCombatComponent()
    -- local ComponentName = CombatComponent:GetName()
    -- UE.UKismetSystemLibrary.PrintString(nil, "OwnerActor:GetCombatComponent(): " .. ComponentName, true, true, UE.FLinearColor(0, 1, 0, 1), 100)
    if CombatComponent then
        CombatComponent:AttackEnd()
    end
    return true
end
return M