--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

---@type AN_AttackStart_C
local M = UnLua.Class()

function M:Received_Notify(MeshComp, Animation)
    local OwnerActor = MeshComp:GetOwner()
    if OwnerActor then
        local WeaponComponents = OwnerActor:GetComponentsByTag(UE.UStaticMeshComponent, "Weapon")

        if WeaponComponents ~= nil then
            local numComponents = WeaponComponents:Num()
            for i = 1, numComponents do
                local Component = WeaponComponents:Get(i)
                if Component then
                    local ComponentName = Component:GetName()
                    -- UE.UKismetSystemLibrary.PrintString(nil, "Found Weapon Component: " .. ComponentName, false, false, UE.FLinearColor(0, 1, 0, 1), 100)
                    -- Component:SetCollisionEnabled(UE.ECollisionEnabled.QueryAndPhysics)
                    Component:SetCollisionResponseToAllChannels(UE.ECollisionResponse.ECR_Block)
                    OwnerActor:StartAttack();
                    -- UE.UKismetSystemLibrary.PrintString(nil, "Enabled collision for: " .. ComponentName, true, true, UE.FLinearColor(0, 1, 0, 1), 100)
                end
            end
        end
    end
          
    return true
end



return M