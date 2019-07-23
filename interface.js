var Handler;
var Handler_Receiver;

window.addEventListener('load', function ()
{
    if (typeof Handler_ != 'undefined')
        Handler = Handler_;
    else if (typeof window.webkit.messageHandlers.Handler_ != 'undefined')
        Handler = window.webkit.messageHandlers.Handler_;
    else
        Handler = null;
});

function SetReceiver(receiver)
{
    Handler_Receiver = receiver;
}

function CallHandler(message)
{
    Handler.postMessage(JSON.stringify(
        {"Receiver": Handler_Receiver, "Message": message}));
}
