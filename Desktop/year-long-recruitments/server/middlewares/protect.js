module.exports.verify= async function verify(req,res,next){
    try {
        let data=req.body; 
        if(data.token){
            //verify from SSO
            let user;
            if(verified){
                res.user=user;
                next();
            }
            else{
                res.json({
                    status:false,
                });
            }
        }
        else{
            res.json({
                status:false,
            });
        }

        
    }catch (error) {
        res.status(500).json({
            message:error.message,
            status:false
        })
    }
}

