//when we want to deliberately send error using boolean error false
const createError = (status,message)=>{
    const err = new Error();
    err.status = status;
    err.message = message;

    return err;
};

export default createError;